void Swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void Quick_Sort(int* arr, int n)//arr:��Ҫ�������ʼλ�ã�n����Ҫ�����Ԫ������
{
	if (n <= 1)
		return;
	int l=0, r=n-1;
	while (l != r)
	{
		for (; *(arr + r) > *(arr) && (l != r); r--);//ѡȡ���Ϊ����������Ҷ����С�
		for (; *(arr + l) <= *(arr) && (l != r); l++);//Ȼ�����ָ������
		Swap(*(arr + l), *(arr + r));//��������ָ��ͣפλ�õ�����
	}
	Swap(*arr, *(arr + l));//����������ָ�����λ�õ���
	Quick_Sort(arr, l);
	Quick_Sort(arr + l + 1, n - l - 1);
}