//https://www.luogu.com.cn/problem/P1063
//能量项链，以前做过，这道题相对于来说有点难度
//#include <iostream>
//#include <string>
//#include <vector>
//#include<algorithm>
//using namespace std;
//int n;
//int nums[205];
//int dp[205][205];
//int main()
//{
//    cin >> n;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> nums[i];
//        nums[i + n] = nums[i];
//    }
//    for(int len=3;len<=n+1;len++)//长度
//        for (int l = 1, r = l + len - 1; r <= 2 * n; l++, r++)//区间
//            for (int k = l + 1; k < r; k++)//截断点
//            {
//                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + nums[l] * nums[k] * nums[r]);
//            }
//    //找最大值
//    int ans = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        ans = max(ans, dp[i][i + n]);
//    }
//    cout << ans;
//    return 0;
//}
