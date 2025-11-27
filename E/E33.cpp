////树的直径
////https://www.luogu.com.cn/problem/U81904
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//const int N = 1e6 + 5;
//
////前向星数据结构
//struct Edge
//{
//    int node;//表示是这条边是哪一个节点；
//    int ne;//表示下一条边的编号
//    int weight;//代表边权
//};
//
//int h[N / 2], idx = 0;//idx表示一共有多少条边，h[i]表示该节点的第一个子节点的编号存在那一条边上
//Edge e[N];
//
//void add(int a, int b,int w)//a和b之间建立边
//{
//    e[idx] = { b,h[a],w };
//    h[a] = idx++;
//}
//
////题目相关定义变量
//int n;
//int vis[N / 2];//代表节点是否被访问
//long ans = 0;//答案
//
//long dfs(int u)//记录从u点向下走的最大长度
//{
//    vis[u] = true;
//
//    long d1 = 0;//记录从u点向下走的最大长度
//    long d2 = 0;//记录以u为向下走的次大长度
//
//    for (int i = h[u]; i != -1; i = e[i].ne)
//    {
//        int j = e[i].node;
//        if (vis[j])continue;
//        int d = e[i].weight+dfs(j);//从u经j点向下走的最大长度
//        if (d > d1)
//        {
//            d2 = d1; d1 = d;
//        }
//        else if (d > d2)d2 = d;
//    }
//    ans = max(ans, d1 + d2);
//    return d1;//记录从u点向下走的最大长度
//}
//
//int main()
//{
//    //预处理
//    memset(h, -1, sizeof(h));
//    cin >> n;
//    int a, b,w;
//
//    for (int i = 1; i <= n - 1; i++)
//    {
//        cin >> a >> b>>w;
//        add(a, b,w);
//        add(b, a,w);
//    }
//    dfs(1);
//    //输出答案
//    cout << ans;
//    return 0;
//}
