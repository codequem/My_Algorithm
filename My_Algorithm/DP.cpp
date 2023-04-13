#include <iostream>
#include <algorithm>

using namespace std;

//01背包问题
//const int N = 10000;
//
//int m, n;
//int v[N], w[N];//编号为i的物品的体积和价值
//int f[N][N];//f[i][j]表示所有只考虑前i个物品，且体积不超过j的选法的集合中总价值的最大值
//int main(void)
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
//	
//	for (int i = 1; i <= n; i++)//从第一个物品一直找到第n个物品
//		for (int j = 0; j <= m; j++)//从容量为零一直找到第m个物品
//		{
//			f[i][j] = f[i - 1][j];//左半边的子集
//			if (j >= v[i])//当总容量大于第i个物品时右半边子集才合法
//				f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);//取左右子集中的最大值
//		}
//	cout << f[n][m] << endl;//输出n个物品，容量为m时的最大价值
//	return 0;
//}

//完全背包问题
//const int N = 10000;
//
//int m, n;
//int v[N], w[N];//编号为i的物品的体积和价值
//int f[N][N];//f[i][j]表示所有只考虑前i个物品，且体积不超过j的选法的集合中总价值的最大值
//int main(void)
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
//	
//	for (int i = 1; i <= n; i++)//从第一个物品一直找到第n个物品
//		for (int j = 0; j <= m; j++)//从容量为零一直找到第m个物品
//		{
//			f[i][j] = f[i - 1][j];//左半边的子集
//			if (j >= v[i])//当总容量大于第i个物品时右半边子集才合法
//				f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);//取左右子集中的最大值
//		}
//	cout << f[n][m] << endl;//输出n个物品，容量为m时的最大价值
//	return 0;
//}

//最长公共子序列问题(给定一个长度为 𝑛 的序列 𝐴 和一个长度为 𝑚 的序列 𝐵,求出一个最长的序列，使得该序列
//既是 𝐴 的子序列，也是 𝐵 的子序列)"字符串 𝑆 的子序列是从 𝑆 中将若干元素提取出来并不改变相对位置形成的序列"


//最长不下降子序列(给定一个长度为 𝑛 的序列 𝐴（𝑛 ≤ 5000），求出一个最长的 𝐴 的子序列，满足该子序列的后一个元素不小于
//前一个元素。)


//以下题为例，展示动态规划的两种实现方式：递归式/记忆化搜索

//题面：山洞里有 𝑀 株不同的草药，采每一株都需要一些时间 𝑡𝑖，每一株也有它自身的价值 𝑣𝑖。给你一段时间 𝑇，
//在这段时间里，你可以采到一些草药。让采到的草药的总价值最大

//朴素DFS做法
//const int M = 10000;
//
//int tcost[M], vget[M];
//int t, n;//你所拥有的时间和草药的种类数
//int ans = 0;
//void dfs(int pos, int tleft, int tans)
//{
//	if (pos == n + 1)
//	{
//		ans = max(ans, tans);
//		return;
//	}
//	dfs(pos + 1, tleft, tans);//不选第pos位的草药
//	if (tleft - tcost[pos] >= 0)//在空间允许的情况下去选择pos位的草药
//	{
//		dfs(pos + 1, tleft - tcost[pos], tans+vget[pos]);
//	}
//
//}
//
//int main(void)
//{
//	cin >> t >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> tcost[i] >> vget[i];
//	dfs(1, t, 0);//从只有一种草药，时间为t，总价值为0开始搜索
//	cout << ans << endl;
//	return 0;
//}
//从爆搜到记忆化只需将朴素dfs中的外部变量消去（这里是tans），并加上记忆化数组
//记忆化搜索做法
//int tcost[103], vget[103];
//int status[103][1003];//另外开一个状态记录的数组，将已经找过的情况记录下来，以防多次搜索，实际上这就是递推的想法
//int t, n;
//
//int dfs(int pos, int tleft)
//{
//	if (status[pos][tleft] != -1) return status[pos][tleft];//如果是已经计算过的状态，就不再重复计算
//	if (n + 1 == pos) return status[pos][tleft]=0;//查找结束，在此做个标记（置零
//	int dfs1 = -1, dfs2 = -1;
//	if (tleft - tcost[pos] >= 0) dfs1=dfs(pos + 1, tleft - tcost[pos])+vget[pos];
//	dfs2 = dfs(pos + 1, tleft);
//	return status[pos][tleft] = max(dfs1, dfs2);//如果还没有查到结果，就返回当前状态的最优抉择
//	//在状态保存数组中实际上是各个n,t取值的最优解
//}
//
//int main(void)
//{
//	cin >> t >> n;
//	memset(status, -1, sizeof(status));
//	for (int i = 1; i <= n; i++)
//		cin >> tcost[i] >> vget[i];
//	cout << dfs(1, t) << endl;
//}

//递推式做法
//int tcost[103], vget[103];
//int f[103][1003];//f[i][j]表示考虑前i种草药，体积不超过j的所有选择中最大的经济收益
//int t, n;
//int main(void)
//{
//	cin >> t >> n;
//	for (int i = 1; i <= n; i++) cin >> tcost[i] >> vget[i];
//	for (int i = 1; i <= n; i++)
//		for (int j = 0; j <= t; j++)
//		{
//			f[i][j] = f[i - 1][j];//不选第i种草药
//			if (j >= tcost[i])
//				f[i][j] = max(f[i][j], f[i-1][j - tcost[i]] + vget[i]);
//		}
//	cout << f[n][t] << endl;
//	return 0;
//}