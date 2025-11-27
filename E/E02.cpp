////P1004，双路线dp，现在有点看不懂//******这道题不能分两次走，因为第一次可能会挤占第二次的空间。
// 一开始
// ,1,2,3
//1, A, 1, 100
//2, 1, 100, 1
//3, 100, 1, B
// 第一次走完
// ,1,2,3
//1, A, 1, 100
//2, 0, 0, 0
//3, 100, 1, B
// 已经走不了最优解了
//// 线性DP O(n^4)
//#include<iostream>
//using namespace std;
//
//const int N = 11;
//int n, x, y, a[N][N];
//int f[N][N][N][N]; //f[i,j,x,y]表示两人从 (1,1) 同步走到 (i,j)、(x,y) 的路径和的最大值
//
//int main() 
//{
//    cin >> n;
//    while (cin >> x >> y >> a[x][y], x);
//
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= n; j++)
//            for (int x = 1; x <= n; x++)
//                for (int y = 1; y <= n; y++)
//                    if (i + j == x + y) {
//                        f[i][j][x][y] = max(max(f[i - 1][j][x - 1][y], f[i - 1][j][x][y - 1]),
//                            max(f[i][j - 1][x - 1][y], f[i][j - 1][x][y - 1])) + a[i][j] + a[x][y];
//                        if (i == x && j == y) f[i][j][x][y] -= a[i][j]; //同一点去重
//                    }
//
//    cout << f[n][n][n][n];
//}
// 线性DP O(n^3)
//#include<bits/stdc++.h>
//using namespace std;
//
//const int N = 11;
//int n, x, y, a[N][N], f[N + N][N][N];
//
//int main() {
//    cin >> n;
//    while (cin >> x >> y >> a[x][y], x);
//
//    for (int k = 2; k <= n + n; k++) //走了k步
//        for (int i = 1; i <= n; i++)   //走到i行
//            for (int x = 1; x <= n; x++) {  //走到x行
//                int j = k - i, y = k - x;
//                if (j >= 1 && j <= n && y >= 1 && y <= n) {
//                    f[k][i][x] = max(max(f[k - 1][i - 1][x - 1], f[k - 1][i - 1][x]),
//                        max(f[k - 1][i][x - 1], f[k - 1][i][x])) + a[i][j] + a[x][y];
//                    if (i == x) f[k][i][x] -= a[i][j];
//                }
//            }
//    cout << f[n + n][n][n];
//}

//P1006//这道题和上题题解完全一样，因为因为交叉与非交叉解等价，永远都可以找到一条非交叉的路替换交叉的路
// 叫做无交叉最优性定理（Non-crossing Optimality Theorem）
// 线性DP O(n^3)
//#include<bits/stdc++.h>
//using namespace std;
//
//const int N = 55;
//int m, n, a[N][N];
//int f[N + N][N][N];
//
//int main() {
//    cin >> m >> n;
//    for (int i = 1; i <= m; i++)
//        for (int j = 1; j <= n; j++) cin >> a[i][j];
//
//    for (int k = 2; k <= m + n; k++) //步数
//        for (int i = 1; i <= m; i++)   //行
//            for (int x = 1; x <= m; x++) {  //行
//                int j = k - i, y = k - x;
//                if (j<1 || j>n || y<1 || y>n) continue;//防止j访问越界
//                f[k][i][x] = max(max(f[k - 1][i - 1][x - 1], f[k - 1][i - 1][x]),
//                    max(f[k - 1][i][x - 1], f[k - 1][i][x])) + a[i][j] + a[x][y];
//                if (i == x) f[k][i][x] -= a[i][j];
//            }
//    cout << f[m + n][m][m];
//}

