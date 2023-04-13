#include <iostream>
#define N 100005
int q[N], t[N];

using namespace std;

void Merge_sort(int q[], int l, int r)
{
    if (r <= l) return;//Ҫ�鲢�������ҽ�С����磬�Ƿ���ֱ�ӷ���
    int mid = (l + r) >> 1;//ȡҪ�鲢��������м�λ����Ϊmid
    Merge_sort(q, l, mid);//���ұ߽��еݹ�Ĺ鲢
    Merge_sort(q, mid + 1, r);//����߽��еݹ�Ĺ鲢

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            t[k++] = q[i++];
        else
            t[k++] = q[j++];
    }//�ϲ����˵����ݣ�ֱ��һ�˵��ﾡͷ
    while (i <= mid)
        t[k++] = q[i++];
    while (j <= r)
        t[k++] = q[j++];
    for (int i = l, j = 0; i <= r; i++, j++)
        q[i] = t[j];//��Ϊԭ����������ȫ�ǼĴ���t����ģ���Ϊ��������в��ܸı�q��������ݣ������ڸ������س�ʼ��q���顣
    //ʵ���ϣ�������Ĺ����У�t�����д洢�������ǲ��ϸı�ģ�ֻ��q�����д���ǽ����
}

int main(void)
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> q[i];
    Merge_sort(q, 0, num - 1);
    for (int i = 0; i < num; i++)
        cout << q[i] << ' ';
    return 0;
}