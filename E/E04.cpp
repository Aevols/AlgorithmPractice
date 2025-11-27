//https://www.luogu.com.cn/problem/T386911
//// 二分+贪心 O(nlogn)
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//const int N = 100010;
//int n, a[N];
//int len, b[N];      //记录上升子序列
//int pos[N], ans[N]; //pos[i]=j 表示a[i]排在b序列中的j位置
//
//int main() {
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
//
//    b[0] = -2e9; //哨兵
//    for (int i = 1; i <= n; i++) {
//        if (b[len] < a[i]) {
//            b[++len] = a[i];
//            pos[i] = len;
//            // printf("%d %d\n",a[i],len);
//        }
//        else {
//            int m = lower_bound(b + 1, b + len + 1, a[i]) - b;
//            b[m] = a[i];
//            pos[i] = m;
//            // printf("%d %d:\n",a[i],m);
//        }
//    }
//    for (int i = n, j = len; i >= 1 && j; i--) {
//        if (pos[i] == j) ans[j--] = a[i];
//    }
//    for (int i = 1; i <= len; i++) printf("%d ", ans[i]);
//}