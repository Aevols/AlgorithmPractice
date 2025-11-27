//基础的打家劫舍问题
//https://leetcode.cn/problems/Gu0c2T/
//分步法
//class Solution
//{
//public:
//    int rob(vector<int>& nums)
//    {
//        const int N = 101;
//        int f[N];
//        f[0] = 0; f[1] = nums[0];
//        for (int i = 2; i <= nums.size(); i++)
//            f[i] = max(f[i - 1], f[i - 2] + nums[i - 1]);
//        return f[nums.size()];
//    }
//};
//分类法
//#include<iostream>
//using namespace std;
//
//const int N = 100010;
//int w[N], f[N][2];
//
//int main() {
//    int n, t; scanf("%d", &t);
//    while (t--) {
//        scanf("%d", &n);
//        for (int i = 1; i <= n; i++)scanf("%d", &w[i]);
//
//        f[1][0] = 0; f[1][1] = w[1];
//        for (int i = 2; i <= n; i++) {
//            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
//            f[i][1] = f[i - 1][0] + w[i];
//        }
//        printf("%d\n", max(f[n][0], f[n][1]));
//    }
//}