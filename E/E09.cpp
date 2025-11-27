//https://www.luogu.com.cn/problem/U227266
//#include<bits/stdc++.h>
//using namespace std;
//
//const int N = 1010;
//int n, m, v, w, f[N];
//
//int main() {
//    scanf("%d%d", &n, &m);
//
//    for (int i = 1; i <= n; i++) {  //枚举物品
//        scanf("%d%d", &v, &w);    //费用 价值
//        for (int j = v; j <= m; j++) //枚举体积
//            f[j] = max(f[j], f[j - v] + w);
//    }
//    printf("%d\n", f[m]);
//}