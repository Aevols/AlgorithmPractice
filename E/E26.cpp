////https://www.luogu.com.cn/problem/P1879
//#include<iostream>
//using namespace std;
//const int MOD = 1e8;
//int map[14];//存储地图，状态压缩方式
//int m, n;
//int states[1 << 14];//合法状态
//int cnt;//计算合法状态总数
//int dp[14][1 << 14];//行，状态
//int main()
//{
//	//预处理，存放地图
//	cin >> m >> n;//m行n列
//	for (int i = 1; i <= m; i++)
//	{
//		int lie = 0;
//		for (int j = 1; j <= n; j++)
//		{
//			int x;
//			cin >> x;
//			lie = (lie << 1) + x;
//		}
//		map[i] = lie;
//	}
//	//存储合法状态
//	for (int i = 0; i < (1 << n); i++)
//	{
//		if (!(i & (i >> 1)))
//			states[cnt++] = i;
//	}
//	//动态规划计算
//	dp[0][0] = 1;
//	for(int i=1;i<=m+1;i++)//遍历行
//		for(int a=0;a<cnt;a++)//遍历该行状态
//			for (int b = 0; b < cnt; b++)//遍历上一行状态
//			{
//				//判断状态a是不是能在这一行土地上种植
//				if ((states[a]&map[i])!=states[a])
//					break;
//				//如果可以种植的话，看能不能与上一行兼容
//				if (!(states[a] & states[b]))
//				{
//					dp[i][states[a]] = (dp[i][states[a]] + dp[i - 1][states[b]]) % MOD;
//				}
//			}
//	cout << dp[m + 1][0];
//	return 0;
//}