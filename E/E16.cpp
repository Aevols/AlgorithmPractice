//// 分组背包 朴素算法 空间优化
//#include<iostream>
//#include<cstring>
//using namespace std;
//
//const int N = 110;
//int f[N], v[N], w[N];
//
//int main() {
//    int n, V, s; cin >> n >> V;
//    for (int i = 1; i <= n; i++) {  //物品组
//        cin >> s;
//        for (int j = 1; j <= s; j++) cin >> v[j] >> w[j];
//
//        for (int j = V; j >= 1; j--) //体积
//            for (int k = 0; k <= s; k++) //个数
//                if (j >= v[k]) f[j] = max(f[j], f[j - v[k]] + w[k]);
//    }
//    cout << f[V];
//}
//https://www.luogu.com.cn/problem/P1757
// 分组背包 O(nm)
//#include<bits/stdc++.h>
//using namespace std;
//
//const int N = 1010;
//int n, m, a, b, c, mx;
//int v[N][N], w[N][N], s[N]; // v[i,j]:第i组第j个物品的体积 s[i]:第i组物品的个数
//int f[N]; // f[i,j]:前i组物品，能放入容量为j的背包的最大值
//
//int main() {
//    cin >> m >> n; //体积 物品
//    for (int i = 1; i <= n; i++) {
//        cin >> a >> b >> c; //体积 价值 所属组数
//        v[c][++s[c]] = a;
//        w[c][s[c]] = b;
//        mx = max(mx, c);
//    }
//
//    for (int i = 1; i <= mx; i++)    //组
//        for (int j = m; j >= 1; j--)     //体积
//            for (int k = 0; k <= s[i]; k++)  //个数
//                if (j >= v[i][k]) f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
//
//    cout << f[m];
//}
//https://www.luogu.com.cn/problem/P1064
//这道题可以通过附件与主件打包的方式形成分组背包问题
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int kMaxN = 32000, kMaxM = 60;
//int v[kMaxM + 5][3], p[kMaxM + 5][3];
//int f[kMaxN + 5];
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    for (int i = 1; i <= m; ++i)
//    {
//        int _v, _p, _q;
//        cin >> _v >> _p >> _q;
//        if (!_q)
//        { // 是主件 
//            v[i][0] = _v;
//            p[i][0] = _p;
//        }
//        else
//        {
//            if (v[_q][1] == 0)
//            { // 是第一个附件 
//                v[_q][1] = _v;
//                p[_q][1] = _p;
//            }
//            else
//            { // 是第二个附件 
//                v[_q][2] = _v;
//                p[_q][2] = _p;
//            }
//        }
//    }
//
//    for (int i = 1; i <= m; ++i)
//    {
//        if (v[i][0] == 0) continue;
//
//        for (int j = n; j >= v[i][0]; --j)
//        {
//
//            // 方案 1: 只买主件
//            f[j] = max(f[j], f[j - v[i][0]] + v[i][0] * p[i][0]);
//
//            // 方案 2: 买主件 + 附件 1
//            if (v[i][1] != 0)
//            {
//                int cost_1 = v[i][0] + v[i][1];
//                int value_1 = v[i][0] * p[i][0] + v[i][1] * p[i][1];
//                if (j >= cost_1)
//                    f[j] = max(f[j], f[j - cost_1] + value_1);
//            }
//
//            // 方案 3: 买主件 + 附件 2
//            if (v[i][2] != 0)
//            {
//                int cost_2 = v[i][0] + v[i][2];
//                int value_2 = v[i][0] * p[i][0] + v[i][2] * p[i][2];
//                if (j >= cost_2)
//                    f[j] = max(f[j], f[j - cost_2] + value_2);
//            }
//
//            // 方案 4: 买主件 + 附件 1 + 附件 2
//            if (v[i][1] != 0 && v[i][2] != 0)
//            {
//                int cost_all = v[i][0] + v[i][1] + v[i][2];
//                int value_all = v[i][0] * p[i][0] + v[i][1] * p[i][1] + v[i][2] * p[i][2];
//                if (j >= cost_all)
//                    f[j] = max(f[j], f[j - cost_all] + value_all);
//            }
//
//        }
//    }
//
//    cout << f[n] << endl;
//}