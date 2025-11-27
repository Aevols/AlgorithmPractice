//朴素加长链长度算法
//https://www.luogu.com.cn/problem/P1880
// 区间DP O(n^3)
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 210;
//int n, a[N], s[N];
//int f[N][N];  //f[i][j]表示把从i到j合并成一堆的得分最小值 
//int g[N][N];  //g[i][j]表示把从i到j合并成一堆的得分最大值 
//
//int main() {
//    memset(f, 0x3f, sizeof f); memset(g, -0x3f, sizeof g);
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i + n] = a[i];
//    for (int i = 1; i <= 2 * n; i++) s[i] = s[i - 1] + a[i], g[i][i] = 0, f[i][i] = 0;
//
//    int minv = 1e9, maxv = -1e9;
//    for (int len = 2; len <= n; len++) 
//    {
//        for (int i = 1, j = len; j <= 2 * n; i++, j++) 
//        {
//            for (int k = i; k < j; k++) 
//            {
//                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
//                g[i][j] = max(g[i][j], g[i][k] + g[k + 1][j] + s[j] - s[i - 1]);
//            }
//            minv = min(minv, f[i][i + n - 1]); //f[1,n]...f[n,2n-1]
//            maxv = max(maxv, g[i][i + n - 1]); //g[1,n]...g[n,2n-1]
//        }
//    }
//    printf("%d\n%d\n", minv, maxv);
//}
////法2： 区间DP 四边形不等式优化 O(n^2)