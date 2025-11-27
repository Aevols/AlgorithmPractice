//现在我们学Kadane's Algorithm和买卖股票问题
//https://www.luogu.com.cn/problem/P1115
//卡丹算法，本质也是个动态规划
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//int n;
//int main()
//{
//    cin >> n;
//    vector<int> nums(n+1);
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> nums[i];
//    }
//    int global_max = nums[1];
//    int current_max = nums[1];
//    for (int i = 2; i <= n; i++)
//    {
//        current_max = max(current_max + nums[i], nums[i]);
//        global_max = max(global_max, current_max);
//    }
//    cout << global_max;
//    return 0;
//}
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/
//class Solution
//{
//public:
//    int maxProfit(vector<int>& prices)
//    {
//        if (prices.size() < 2) {
//            return 0;
//        }
//
//        // 1. 构建差分数组 nums
//        vector<int> nums;
//        for (int i = 1; i < prices.size(); i++)
//        {
//            nums.push_back(prices[i] - prices[i - 1]);
//        }
//
//        // 2. 求最大子数组和 (Kadane's Algorithm)
//
//        // current_max: 必须初始化为 0 或 nums[0]
//        int current_max = 0;
//
//        // global_max: 必须初始化为 0，因为利润不能小于 0
//        int global_max = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            current_max = max(current_max + nums[i], nums[i]);
//            global_max = max(global_max, current_max);
//        }
//        return global_max;
//    }
//};
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
// //这段代码是错的，错在dp[1][0] = -1e3;设置的太大了，应该更小一点，因为还是边界太近有崩溃的可能
//class Solution
//{
//public:
//    int maxProfit(vector<int>& prices)
//    {
//        int n = prices.size();
//        vector<vector<int>>dp(2, vector<int>(n + 1));
//        dp[0][0] = 0;
//        dp[1][0] = -1e5;//大一点
//        for (int i = 1; i <= n; i++)
//        {
//            dp[0][i] = max(dp[1][i - 1] + prices[i - 1], dp[0][i - 1]);
//            dp[1][i] = max(dp[0][i - 1] - prices[i - 1], dp[1][i - 1]);
//        }
//        return(dp[0][n]);
//
//    }
//};