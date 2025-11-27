//好像有点困难
// 单调队列 O(n*W)
//#include<iostream>
//using namespace std;
//
//const int N = 40010;
//int n, W, w, v, m, q[N];
//int f[N], g[N];
//
//int main() {
//    scanf("%d%d", &n, &W);        //种类n,容量W
//    while (n--) 
//    {
//        memcpy(g, f, sizeof(f));    //f备份
//        scanf("%d%d%d", &v, &w, &m); //价值,重量,数量
//        for (int j = 0; j < w; j++) 
//        {   //0,1,2...w-1个类
//            int h = 1, t = 0;
//            for (int k = j; k <= W; k += w)//k是用于更新的关键
//            { //0,w,2w,3w...
//                while (h <= t && q[h] < k - m * w) h++; //[k-m*w...k-w],k//清队头
//                while (h <= t && g[k] >= g[q[t]] + (k - q[t]) / w * v) t--; //q[t]...k//清队尾
//                q[++t] = k;
//                f[k] = g[q[h]] + (k - q[h]) / w * v; //q[h]...k
//            }
//        }
//    }
//    printf("%d\n", f[W]);
//}