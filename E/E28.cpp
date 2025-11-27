////https://www.luogu.com.cn/problem/P1775
////区间dp，实际上也可以写递归，但是递归容易stack overflow，实际生产中特别容易出问题，虽然好用，但也不要太过依赖
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//const int N = 305;
//int n;
//int nums[N];
//long long pre[N];
//long long dp[N][N];
//int main()
//{
//    //输入预处理
//    cin >> n;
//    memset(dp, 0x3f, sizeof(dp));//fill(ForwardIt first, ForwardIt last, const T& value);
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> nums[i];
//        pre[i]=pre[i-1]+nums[i];
//        //取长度为1的区间，dp值为自身
//        dp[i][i] = 0;
//    }
//    //求区间dp
//    for(int length=2;length<=n;length++)//区间长度
//        for(int l=1,r=length;r<=n;l++,r++)
//            for (int k = l; k <r; k++)//注意yyyyyyyyyyyyyyyy不能写成k<length
//            {
//                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + pre[r] - pre[l - 1]);
//            }
//    cout << dp[1][n];
//    return 0;
//}
//https://www.luogu.com.cn/problem/P2308
//这道题是上道题的加强版，要记录路径
//#include <iostream>
//#include <cstring>
//#include <vector>
//using namespace std;
//const int N = 305;
//int n;
//int nums[N];
//long long pre[N];
//long long dp[N][N];
//int mapdp[N][N];//记录路径
//int main()
//{
//    //输入预处理
//    cin >> n;
//    memset(dp, 0x3f, sizeof(dp));//fill(ForwardIt first, ForwardIt last, const T& value);
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> nums[i];
//        pre[i]=pre[i-1]+nums[i];
//        //取长度为1的区间，dp值为自身
//        dp[i][i] = 0;
//    }
//    //求区间dp
//    for(int length=2;length<=n;length++)//区间长度
//        for(int l=1,r=length;r<=n;l++,r++)
//            for (int k = l; k <r; k++)//注意yyyyyyyyyyyyyyyy不能写成k<length
//            {
//                if (dp[l][r] > dp[l][k] + dp[k + 1][r] + pre[r] - pre[l - 1])mapdp[l][r] = k;
//                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + pre[r] - pre[l - 1]);
//            }
//
//
//    cout << dp[1][n];
//    return 0;
//}
//
