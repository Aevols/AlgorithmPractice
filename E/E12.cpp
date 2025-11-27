////////https://www.luogu.com.cn/problem/U162981
////////这道题还有一道坑就是，可能会出现负数的情况，所以说ans要取应该比较小的值，不应该为0
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//const int N = 2e5 + 5;
//int n, m;
//int nums[N];
//int s[N];//保留前缀和
//int q[N];//窗口，储存下标的
//int main()
//{
//    cin >> n >> m;
//    int a;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> a;
//        nums[i] = a;
//        s[i] = s[i - 1] + a;
//    }
//    int ans = -10000;//答案
//    for (int i = 1,h=1,t=0; i <= n; i++)//i是指向的是现在我们求的前i个数的答案
//    {
//        //队头出队
//        while (h <= t && q[h] < i - m)h++;
//        //队尾出队
//        while (h <= t && s[q[t]] > s[i - 1])t--;
//        //队尾入队
//        q[++t] = i - 1;/////////////注意：这里把i-1写成了s[i-1];
//        ans = max(ans, s[i] - s[q[h]]);
//    }
//    cout << ans;
//    return 0;
//}
////没那么难嘛，好好加油
