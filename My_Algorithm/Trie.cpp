#include <iostream>
#include <string>

using namespace std;
//这是指针实现，简洁易懂，只是空间爆炸
typedef struct Trie
{
	bool flag = false;
	Trie* next[26] = { nullptr };
	int prefix_num = 0;
}Trie;
typedef Trie* pos;//指向树上任意一个节点，也就是位置

void Insert(string word, Trie& T);//向树里插入单词
bool Check(string word, Trie& T);//查询某个单词是否存在
int Prefix_num(string prefix, Trie& T);//查询某个前缀根下有多少词汇
//实际上来说，我还可以加删除操作，但是并不常用，这里就不是实现了。

void Insert(string word, Trie& T)
{
    pos temp = &T;
    for (int i = 0; i < word.length(); i++)//要插入的串有多长就走多远咯
    {
        if (temp->next[word[i] - 'a'] == nullptr) temp->next[word[i] - 'a'] = new Trie;//插入对应的分支
        temp->prefix_num++;//更新路径上的前缀串数
        temp = temp->next[word[i] - 'a'];//temp沿着树接着往下走
    }
    temp->flag = true;//标记结束点
    temp->prefix_num++;//别忘了更新前缀串数
}

bool Check(string word, Trie& T)
{
    pos temp = &T;
    for (int i = 0; i < word.length(); i++)
    {
        if (temp->next[word[i] - 'a'] == nullptr) return false;
        temp = temp->next[word[i] - 'a'];//查询可太简单了，沿着路径走就行了
    }
    return temp->flag ? true : false;
}

int Prefix_num(string prefix, Trie& T)
{
    pos temp = &T;
    for (int i = 0; i < prefix.length(); i++)
    {
        if (temp->next[prefix[i] - 'a'] == nullptr) return 0;
        temp = temp->next[prefix[i] - 'a'];
    }
    return temp->prefix_num;
}

//下面我们来用数组来实现Trie树
const int Maxn = 1e6 + 5;//这个值决定了这个字典能存多少字母（不是单词数）
int trie[Maxn][26];//实际上数组形式的树每一层都只存了一个字母
//trie[上节点编号][下方连接的字母]=下方连接的字符的节点编号
int cnt[Maxn];//记录每一个词的结束节点id
int prefix_num[Maxn];//记录每一个前缀后面跟了多少单词数
int id;//记录现在已经使用到的节点id

void insert(string s);
int find(string s);
int find_prefix_nums(string s);

void insert(string s)
{
    int p = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int x = s[i] - 'a';
        if (trie[p][x] == 0) trie[p][x] = ++id;
        p = trie[p][x];
        prefix_num[p]++;
    }
    cnt[p]++;
}

int find(string s)
{
    int p = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int x = s[i] - 'a';
        if (trie[p][x] == 0)return 0;
        p = trie[p][x];
    }
    return cnt[p];
}

int find_prefix_nums(string s)
{
    int p = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int x = s[i] - 'a';
        if (trie[p][x] == 0)return 0;
        p = trie[p][x];
    }
    return prefix_num[p];
}
//我们先后插入单词"abc",“abb”,“bca”,“bc”，那编号就是这样
/*
trie[0][0]=1;trie[0][1]=5;//0号节点指向代表字符‘a'的节点1，和字符‘b’的节点2
trie[1][1]=2;//代表字符‘a'的节点1指向代表字符‘b’的节点2
trie[2][1]=4;trie[2][2]=3;//代表字符‘b’的节点2指向代表字符‘b’的节点4，和字符‘c’的节点3//至此abc,abb存储完毕
trie[5][2]=6;
trie[6][0]=7;
其余trie[i][j]都为0，即空节点；
cnt[4]=cnt[3]=cnt[6]=cnt[7]=1;*///节点3是abc的结束，节点4是abb的结束