////https://www.luogu.com.cn/problem/P1776
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int n, W;
//vector<int> v, w;
//
//int main()
//{
//    cin >> n >> W;
//    int vv, ww, mm;
//
//    for (int i = 0; i < n; i++)
//    {
//        cin >> vv >> ww >> mm;
//        for (int j = 1; j <= mm; j <<= 1)
//        {
//            v.push_back(vv * j);
//            w.push_back(ww * j);
//            mm -= j;
//        }
//        if (mm)
//        {
//            v.push_back(vv * mm);
//            w.push_back(ww * mm);
//        }
//    }
//
//    vector<int> dp(W + 1, 0);
//
//    for (int i = 0; i < v.size(); i++)
//        for (int j = W; j >= w[i]; j--)
//            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
//
//    cout << dp[W] << endl;
//    return 0;
//}
