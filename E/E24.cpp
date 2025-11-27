//#include <iostream>
//#include <cstring>
//using namespace std;
//
//const int N = 100010;
//int w[N], f[N][2];
//
//int main() {
//    int n; cin >> n;
//    for (int i = 1; i <= n; i++) cin >> w[i];
//
//    f[0][0] = 0; f[1][0] = 0; f[1][1] = -w[1];
//
//    for (int i = 2; i <= n; i++) {
//        f[i][0] = max(f[i - 1][0], f[i - 1][1] + w[i]);
//        f[i][1] = max(f[i - 1][1], f[i - 2][0] - w[i]);
//    }
//    cout << f[n][0];
//}