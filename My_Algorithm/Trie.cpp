#include <iostream>
#include <string>

using namespace std;
//����ָ��ʵ�֣�����׶���ֻ�ǿռ䱬ը
typedef struct Trie
{
	bool flag = false;
	Trie* next[26] = { nullptr };
	int prefix_num = 0;
}Trie;
typedef Trie* pos;//ָ����������һ���ڵ㣬Ҳ����λ��

void Insert(string word, Trie& T);//��������뵥��
bool Check(string word, Trie& T);//��ѯĳ�������Ƿ����
int Prefix_num(string prefix, Trie& T);//��ѯĳ��ǰ׺�����ж��ٴʻ�
//ʵ������˵���һ����Լ�ɾ�����������ǲ������ã�����Ͳ���ʵ���ˡ�

void Insert(string word, Trie& T)
{
    pos temp = &T;
    for (int i = 0; i < word.length(); i++)//Ҫ����Ĵ��ж೤���߶�Զ��
    {
        if (temp->next[word[i] - 'a'] == nullptr) temp->next[word[i] - 'a'] = new Trie;//�����Ӧ�ķ�֧
        temp->prefix_num++;//����·���ϵ�ǰ׺����
        temp = temp->next[word[i] - 'a'];//temp����������������
    }
    temp->flag = true;//��ǽ�����
    temp->prefix_num++;//�����˸���ǰ׺����
}

bool Check(string word, Trie& T)
{
    pos temp = &T;
    for (int i = 0; i < word.length(); i++)
    {
        if (temp->next[word[i] - 'a'] == nullptr) return false;
        temp = temp->next[word[i] - 'a'];//��ѯ��̫���ˣ�����·���߾�����
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

//������������������ʵ��Trie��
const int Maxn = 1e6 + 5;//���ֵ����������ֵ��ܴ������ĸ�����ǵ�������
int trie[Maxn][26];//ʵ����������ʽ����ÿһ�㶼ֻ����һ����ĸ
//trie[�Ͻڵ���][�·����ӵ���ĸ]=�·����ӵ��ַ��Ľڵ���
int cnt[Maxn];//��¼ÿһ���ʵĽ����ڵ�id
int prefix_num[Maxn];//��¼ÿһ��ǰ׺������˶��ٵ�����
int id;//��¼�����Ѿ�ʹ�õ��Ľڵ�id

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
//�����Ⱥ���뵥��"abc",��abb��,��bca��,��bc�����Ǳ�ž�������
/*
trie[0][0]=1;trie[0][1]=5;//0�Žڵ�ָ������ַ���a'�Ľڵ�1�����ַ���b���Ľڵ�2
trie[1][1]=2;//�����ַ���a'�Ľڵ�1ָ������ַ���b���Ľڵ�2
trie[2][1]=4;trie[2][2]=3;//�����ַ���b���Ľڵ�2ָ������ַ���b���Ľڵ�4�����ַ���c���Ľڵ�3//����abc,abb�洢���
trie[5][2]=6;
trie[6][0]=7;
����trie[i][j]��Ϊ0�����սڵ㣻
cnt[4]=cnt[3]=cnt[6]=cnt[7]=1;*///�ڵ�3��abc�Ľ������ڵ�4��abb�Ľ���