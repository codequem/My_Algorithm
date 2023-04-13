#include <iostream>
#define N 100005
int q[N], t[N];

using namespace std;

void Merge_sort(int q[], int l, int r)
{
    if (r <= l) return;//要归并的数组右界小于左界，非法，直接返回
    int mid = (l + r) >> 1;//取要归并的数组的中间位置作为mid
    Merge_sort(q, l, mid);//对右边进行递归的归并
    Merge_sort(q, mid + 1, r);//对左边进行递归的归并

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            t[k++] = q[i++];
        else
            t[k++] = q[j++];
    }//合并两端的数据，直到一端到达尽头
    while (i <= mid)
        t[k++] = q[i++];
    while (j <= r)
        t[k++] = q[j++];
    for (int i = l, j = 0; i <= r; i++, j++)
        q[i] = t[j];//因为原来的排序结果全是寄存在t数组的（因为排序过程中不能改变q数组的数据），现在给他还回初始的q数组。
    //实际上，在排序的过程中，t数组中存储的数据是不断改变的，只有q数组中存的是结果。
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