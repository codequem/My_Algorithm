void Swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void Quick_Sort(int* arr, int n)//arr:需要排序的起始位置，n：需要排序的元素数量
{
	if (n <= 1)
		return;
	int l=0, r=n-1;
	while (l != r)
	{
		for (; *(arr + r) > *(arr) && (l != r); r--);//选取左端为基数，因此右端先行。
		for (; *(arr + l) <= *(arr) && (l != r); l++);//然后左端指针再走
		Swap(*(arr + l), *(arr + r));//交换两个指针停驻位置的数据
	}
	Swap(*arr, *(arr + l));//交换基数和指针结束位置的数
	Quick_Sort(arr, l);
	Quick_Sort(arr + l + 1, n - l - 1);
}