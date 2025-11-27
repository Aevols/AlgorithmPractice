//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//const int N = 1005;
//int n, k, price[N];
//int dp[N][105][2];//天数，笔数，是否持有股票1_based
//int main()
//{
//    cin >>n>> k;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> price[i];
//    }
//    //处理边界条件
//    for (int i = 0; i <= k; i++)
//        dp[0][i][1] = -1e6;
//    for(int i=1;i<=n;i++)//天数
//        for (int j = 1; j <= k; j++)//交易笔数
//            //这里有一个问题，能不能优化交易笔数，前j天最多进行i/2（向下取整）笔交易
//        {
//            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + price[i]);
//            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - price[i]);
//        }
//    cout << dp[n][k][0];
//    return 0;
//}
//空间优化
//#include<iostream>
//#include<cstring>
//using namespace std;
//
//const int N = 100010, M = 110;
//int w[N], f[M][2];
//
//int main() {
//    int n, k; cin >> n >> k;
//    for (int i = 1; i <= n; i++) cin >> w[i];
//
//    for (int j = 0; j <= k; j++) f[j][1] = -1e6;
//
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= k; j++) {
//            f[j][0] = max(f[j][0], f[j][1] + w[i]);
//            f[j][1] = max(f[j][1], f[j - 1][0] - w[i]);
//        }
//    cout << f[k][0];
//}

