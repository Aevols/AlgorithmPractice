//// 单调队列优化
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//int n, m;
//int f[1010], g[1010];
//int q[1010];
//
//void ZeroOnePack(int v, int w) {
//    for (int j = m; j >= v; j--)
//        f[j] = max(f[j], f[j - v] + w);
//}
//void CompletePack(int v, int w) {
//    for (int j = v; j <= m; j++)
//        f[j] = max(f[j], f[j - v] + w);
//}
//void MultiplePack(int v, int w, int s) {
//    memcpy(g, f, sizeof(f));
//    for (int j = 0; j < v; j++) {
//        int h = 0, t = -1;
//        for (int k = j; k <= m; k += v) {
//            if (h <= t && q[h] < k - s * v) h++;
//            if (h <= t) f[k] = max(g[k], g[q[h]] + (k - q[h]) / v * w);
//            while (h <= t && g[k] >= g[q[t]] + (k - q[t]) / v * w) t--;
//            q[++t] = k;
//        }
//    }
//}
//int main() {
//    int v, w, s;
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++) {
//        scanf("%d %d %d", &v, &w, &s);
//        if (s == -1)
//            ZeroOnePack(v, w);     //01背包 
//        else if (s == 0)
//            CompletePack(v, w);    //完全背包 
//        else
//            MultiplePack(v, w, s);  //多重背包 
//    }
//    cout << f[m];
//}
//https://www.luogu.com.cn/problem/P1833
//#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <cstring>
//
//using namespace std;
//
//// N为dp数组f的最大容量，M为拆分后的物品数组a, b, c的最大容量
//// 根据题目 T_e - T_s <= 1000, n <= 10000
//// T_e - T_s 即背包容量 M <= 1000. N 应至少为 1001.
//// 拆分后的物品数: 最多 n * log2(100) 约等于 10000 * 7 = 70000. M 设为 80000 即可。
//const int MAX_M = 1005; // 背包容量上限 M <= 1000 + 5
//const int MAX_N_AFTER_SPLIT = 80005; // 拆分后的最大物品数
//
//// a[i]: 第i个拆分后物品的耗费时间 (v)
//// b[i]: 第i个拆分后物品的美学值 (w)
//// c[i]: 物品类型 (1: 0-1背包, 0: 完全背包)
//int a[MAX_N_AFTER_SPLIT], b[MAX_N_AFTER_SPLIT], c[MAX_N_AFTER_SPLIT];
//
//// f[j]: 总时间j能获得的最大美学值
//int f[MAX_M];
//
//// 辅助函数：将hh:mm格式时间转为分钟
//int time_to_minutes(const string& t_str) {
//    int h1, h2, m1, m2;
//    // 使用sscanf解析字符串
//    sscanf(t_str.c_str(), "%d:%d", &h1, &m1);
//    return h1 * 60 + m1;
//}
//
//int main() {
//    // Ts, Te 格式为 hh:mm，n 为樱花树棵数
//    string Ts_str, Te_str;
//    int n;
//
//    // 读取时间字符串和棵树n
//    if (!(cin >> Ts_str >> Te_str >> n)) return 0;
//
//    // 计算总可用时间 T_total，即背包容量 M
//    int Ts_minutes = time_to_minutes(Ts_str);
//    int Te_minutes = time_to_minutes(Te_str);
//
//    // M: 背包容量（总时间）
//    int m = Te_minutes - Ts_minutes;
//    // 题目保证 Te >= Ts 且 T_e-T_s <= 1000
//    if (m < 0) {
//        // 尽管题目保证同一天，但如果 Te < Ts，则为负时间，这里处理为0分钟或根据实际情况处理
//        // 根据题目，T_e-T_s <= 1000, 且为同一天，m >= 0
//        m = 0;
//    }
//
//    // v: 耗费时间 Ti, w: 美学值 Ci, s: 次数 Pi
//    int v, w, s;
//
//    int num = 1; // 记录拆分后的物品总数 (从1开始编号)
//
//    for (int i = 1; i <= n; i++) {
//        // 读取 Ti, Ci, Pi
//        if (!(scanf("%d%d%d", &v, &w, &s))) break;
//
//        if (s == 0) {            // 完全背包 (看无数次 P_i = 0)
//            a[num] = v;
//            b[num] = w;
//            c[num++] = 0;       // 背包类型: 0表示完全背包
//        }
//        else {                // 多重背包 (看有限次数 P_i > 0)
//            // if(s == -1) s = 1; // 题目中 P_i >= 0, 故无需此行。P_i=1 即 0-1 背包，会被二进制拆分正确处理。
//
//            // 二进制拆分
//            int k = 1;
//            int rest_s = s;
//
//            while (rest_s >= k) {
//                a[num] = k * v;    // 耗费时间
//                b[num] = k * w;    // 美学值
//                c[num++] = 1;      // 背包类型: 1表示0-1背包
//                rest_s -= k;
//                k <<= 1;
//            }
//            if (rest_s > 0) {
//                a[num] = rest_s * v;
//                b[num] = rest_s * w;
//                c[num++] = 1;    // 剩余部分打包成一个0-1背包物品
//            }
//        }
//    }
//
//    // 动态规划求解
//    // num 为拆分后物品总数 + 1
//    for (int i = 1; i < num; i++) {
//        if (c[i] == 1) { // 0-1背包
//            for (int j = m; j >= a[i]; j--)
//                f[j] = max(f[j], f[j - a[i]] + b[i]);
//        }
//        else {         // 完全背包
//            for (int j = a[i]; j <= m; j++)
//                f[j] = max(f[j], f[j - a[i]] + b[i]);
//        }
//    }
//
//    cout << f[m] << endl;
//
//    return 0;
//}