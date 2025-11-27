////https://www.luogu.com.cn/problem/P2871
//// 逆序枚举，优化空间
//#include<bits/stdc++.h>
//using namespace std;
//
//const int M = 13000;
//int n, m, v, w;
//int f[M];
//
//int main() {
//    scanf("%d%d", &n, &m);
//
//    for (int i = 1; i <= n; i++) {  //枚举物品
//        scanf("%d%d", &v, &w);    //费用 价值
//        for (int j = m; j >= v; j--) //枚举体积
//            f[j] = max(f[j], f[j - v] + w);
//    }
//    printf("%d\n", f[m]);
//}

////https://www.luogu.com.cn/problem/P1060
//#include <iostream>
//#include <string>
//#include <vector>
//#include<cmath>
//using namespace std;
//int value, m;
//int v, weight;
//int dp[30000];
//int main()
//{
//    cin >> value >> m;
//   
//    for (int i = 1; i <= m; i++)//遍历物品
//    {
//        cin >> v >> weight;
//        for (int j=value;j>=v; j--)
//        {
//            dp[j] = max(dp[j], dp[j - v] + v * weight);
//        }
//    }
//    cout << dp[value];
//    return 0;
//}

//https://www.luogu.com.cn/problem/P7223

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//#define Mod 998244353
//
//using namespace std;
//
//long long binpow(long long b, long long p, long long k) {
//	b %= k;
//	long long res = 1;
//	while (p > 0) {
//		if (p & 1)
//			res = res * b % k;
//		b = b * b % k;
//		p >>= 1;
//	}
//	return res;
//}
//
//int main() {
//	
//	
//	long long n, p;
//	long long ans = 1;
//
//	
//	if (!(cin >> n >> p)) return 0;
//
//	// 使用 vector 替代 C 风格数组
//	vector<long long> a(n);
//
//	for (long long i = 0; i < n; ++i) {
//		cin >> a[i];
//	}
//
//	for (long long i = 0; i < n; ++i) {
//		// 计算 (p^a[i] % Mod + 1) % Mod
//		long long term = (binpow(p, a[i], Mod) + 1) % Mod;
//
//		ans = ans * term % Mod;
//	}
//
//	// 使用 cout 进行输出
//	cout << ans << "\n";
//
//	return 0;
//}
