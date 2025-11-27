////https://www.luogu.com.cn/problem/P1896
////又来到了状态压缩，当时就是这个水平
//#include<iostream>
//#include<string>
//using namespace std;
//int n, k;
//int cnt=0;//计算一行中有多少合法状态
//int states[1 << 12];//存储合法状态,0_based
//int num[1 << 12]; //每个合法状态包含的国王数,0_based;
//long long dp[12][144][1<<12];//行数，国王数，状态
//int main()
//{
//	cin >> n >> k;
//	//存储状态，这里可以优化，我们先不管
//	for (int i = 0; i <(1 << n); i++)
//	{
//		if (!(i & (i >> 1)))
//		{
//			states[cnt] = i;
//			//计算国王数
//			for (int j = 0; j < n; j++)
//			{
//				if (1 & (i >> j))
//					num[cnt]++;
//			}
//			cnt++;
//		}
//	}
//	/*for (int i = 0; i < cnt;i++)
//	{
//		cout << states[i] << " " << num[i] << endl;
//	}*/
//	//cout << cnt;是对的
//	//状压计算
//	dp[0][0][0] = 1;//第0行有0个国王状态为0时也是一种状态，方便后面加上去
//	for(int i=1;i<=n+1;i++)//遍历行，多算一行方便后续输出
//		for(int j=0;j<=k;j++)//遍历国王数（总共花费了多少个国王）
//			for (int a = 0; a < cnt; a++)//遍历该行状态
//				for (int b = 0; b < cnt; b++)//遍历上一行状态
//				{
//					//剪枝，一行的国王数已经超过要花费的国王了
//					if (j - num[a]<0)break;
//					//判断能否满足条件
//					//！！！！！！！条件判断这里写错了，死活找不出，==的优先级大于&，所以
//					//这里的判断一直是错的
//					else if (!(states[a] & states[b])
//						&& !(states[a] & (states[b] >> 1))
//						&& !(states[a] & (states[b] << 1)))
//					{
//						dp[i][j][a] += dp[i - 1][j - num[a]][b];
//						//cout << "dp[" << i << "]" << "[" << j << "]" << "[" << a << "]=" << dp[i][j][a]<<endl;
//					}
//				}
//	cout << dp[n + 1][k][0] << endl;
//	return 0;
//}