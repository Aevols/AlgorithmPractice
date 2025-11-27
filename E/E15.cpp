////二维费用 01背包
//#include<iostream>
//using namespace std;
//
//int n, V, W;
//int f[110][110]; // f[j,k]:前i个物品，体积≤j，重量≤k 的最大价值
//
//int main() {
//    cin >> n >> V >> W; //物品 容量 承重
//    for (int i = 1, v, w, val; i <= n; i++) { //物品 
//        cin >> v >> w >> val; //体积 重量 价值
//        for (int j = V; j >= v; j--) //体积
//            for (int k = W; k >= w; k--) //重量
//                f[j][k] = max(f[j][k], f[j - v][k - w] + val);
//    }
//    cout << f[V][W];
//}
//https://www.luogu.com.cn/problem/P1855
////二维费用 01背包
//#include <iostream>
//using namespace std;
//
//int n, V, W;
//int f[210][210]; //f[j,k]:前i个物品，体积≤j，重量≤k 的最大价值
//
//int main() {
//    cin >> n >> V >> W; //物品 容量 承重
//    for (int i = 1, v, w; i <= n; i++) { //物品 
//        cin >> v >> w; //体积 重量
//        for (int j = V; j >= v; j--)    //体积
//            for (int k = W; k >= w; k--)    //重量
//                f[j][k] = max(f[j][k], f[j - v][k - w] + 1);
//    }
//    cout << f[V][W];
//}