/*2022��12��25��11:39:22
KMP�㷨*/
#include <iostream>
#include <string>
#define N 1000005

using namespace std;

int Next[N];//һ��ʼ����ȫ���
void getNext(const string& P);
void KMP(const string& S, const string& P);

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);//����cin
    string in, test;
    cin >> in;
    cin >> test;
    KMP(in, test);
    /*for (int i = 0; i < test.length() - 1; i++)
        cout << Next[i] << ' ';*/
    cout << 0 <<' ';
    for (int i = 0; i < test.length()-1; i++)
        cout << Next[i] + 1 << ' ';//���ǵĽ̲�Ҫ�������next�����ֵ������
    system("pause");
    return 0;
}

void getNext(const string& P)
{
    //ָ��k���к���Ҫ�����壬����ֵ����Ŀǰƥ�䵽�����ͬǰ׺�ĳ���
    //��ָ��i����������Ŀǰ����������ַ���
    //ָ��i��ָ��kǰ�棬�ҳ�ʼʱi=1��k=0
    for (int i = 1, k = 0; i < P.length(); i++)//i��һֱ����ǰ�ߵ�
    {
        while (k && P[k] != P[i]) k = Next[k - 1];//������ƥ���һֱ���ˣ�����ָ��k���˵�ʲôλ����ͨ����Next[k-1]ȷ����
        if (P[k] == P[i]) k++;
        Next[i] = k;//ƥ��ͽ��Ų�ѯ��һλ
    }
}
void KMP(const string& S, const string& P)
{
    bool succ = false;
    getNext(P);
    for (int i = 0, k = 0; i < S.length(); i++)
    {
        while (k && P[k] != S[i]) k = Next[k - 1];//������ƥ���һֱ����
        if (P[k] == S[i]) k++;
        if (k == P.length())
        {
            succ = true;
            cout << i - P.length() + 1 << endl;
            k = Next[k - 1];//Ϊ�˵õ�����ƥ���λ��
        }
    }
    if (!succ)
        cout << -1 << endl;
}