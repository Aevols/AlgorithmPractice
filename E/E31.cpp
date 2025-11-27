//https://www.acwing.com/problem/content/description/293/
//#include <iostream>
//#include <cstring>
//#include <vector>
//#include<algorithm>
//using namespace std;
//const int N = 12, M = 1 << N;
//bool st[M];         //st[i]存储合并列的状态i是否合法  
//long long dp[N][M];  //dp[i][j]表示摆放第i列，状态为j时的方案数 
//
//int main()
//{
//    int n,m;
//    while (cin >> n >> m, n | m)
//    {
//    // 预处理：判断合并列的状态i是否合法 
//    // 合并列即两列状态合并之意，对应后面的st[j|k]      
//    // 如果合并列的某行是1表示横放，是0表示竖放 
//    // 如果合并列不存在连续的奇数个0，即为合法状态 
//        for (int i = 0; i < (1 << n); i++)
//        {
//            st[i] = true;//因为默认是false
//            int cnt = 0;
//            for (int j = 0; j < n; j++)
//            {
//                if (i >> j & 1) 
//                {           //如果是1
//                    if (cnt & 1) 
//                    {          //如果连续0的个数是奇数 
//                        st[i] = false; break; //记录i不合法           
//                    }
//                }
//                else cnt++;
//            }
//            if (cnt % 2 == 1)st[i] = false;//处理高位0
//        }
//        //每次计算的时候都要重新更新dp值
//        memset(dp, 0, sizeof(dp));
//        dp[0][0] = 1;
//        //状态压缩
//        for (int i = 1; i <= m; i++)//遍历当前列
//            for (int a = 0; a < 1 << n;a++)//遍历当前列状态
//                for (int b = 0; b < 1 << n; b++)//遍历上一列
//                {
//                    if (st[a | b] && (a & b) == 0)
//                        dp[i][a] += dp[i - 1][b];
//                }
//        cout << dp[m][0] << endl;
//    }
//    return 0;
//}
