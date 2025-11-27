//链式前向星（基于头插法）+树的重心（链式前向星虽然相对来说会哪一点，但是这是必须掌握的，所以说这里我们麻烦一点），说实话有点难，今天做一辆题算了
//https://www.luogu.com.cn/problem/U104609
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//const int N = 1e5 + 5;
//
////前向星数据结构
//struct Edge
//{
//    int node;//表示是这条边是哪一个节点；
//    int ne;//表示下一条边的编号
//};
//
//int h[N / 2], idx = 0;//idx表示一共有多少条边，h[i]表示该节点的子节点的编号存在那一条边上
//Edge e[N];
//
//void add(int a, int b)//a和b之间建立边
//{
//    e[idx] = { b,h[a] };
//    h[a] = idx++;
//}
//
////题目相关定义变量
//int n;
//int vis[N / 2];//代表节点是否被访问
//vector<int> ans;//存储答案
//int MaxSonWeight = N;//存储最大子树的重量
//
//int dfs(int u)
//{
//    vis[u] = true;
//
//    int size = 0;//记录子树的最大重量
//    int sum = 1;//记录以u为子树的节点数
//
//    for (int i = h[u]; i != -1; i = e[i].ne)
//    {
//        int j = e[i].node;
//        if (vis[j])continue;
//
//        int s = dfs(j);//记录以j为子节点的子树大小
//        size = max(size, s);
//        sum += s;
//    }
//
//    //这里是更新答案的地方
//    size = max(size, n - sum); //考虑“父方向”的剩余节点
//
//    if (size < MaxSonWeight)
//    {
//        MaxSonWeight = size;
//        ans.clear();
//        ans.push_back(u);
//    }
//    else if (size == MaxSonWeight)
//    {
//        ans.push_back(u);
//    }
//
//    return sum;
//}
//
//int main()
//{
//    //预处理
//    memset(h, -1, sizeof(h));
//    cin >> n;
//    int a, b;
//
//    for (int i = 1; i <= n - 1; i++)
//    {
//        cin >> a >> b;
//        add(a, b);
//        add(b, a);
//    }
//
//    dfs(1);
//
//    //输出答案
//    sort(ans.begin(), ans.end());
//    for (auto x : ans)
//        cout << x << " ";
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//const int N = 1e5 + 5;
//
////前向星数据结构
//struct Edge
//{
//    int node;//表示是这条边是哪一个节点；
//    int ne;//表示下一条边的编号
//};
//
//int h[N / 2], idx = 0;//idx表示一共有多少条边，h[i]表示该节点的子节点的编号存在那一条边上
//Edge e[N];
//
//void add(int a, int b)//a和b之间建立边
//{
//    e[idx] = { b,h[a] };
//    h[a] = idx++;
//}
//
////题目相关定义变量
//// int n;
//int vis[N / 2];//代表节点是否被访问
//vector<int> ans;//存储答案
//int MaxSonWeight = N;//存储最大子树的重量
//int y = 0; // 存储距离总和
//
//int dfs(int u)
//{
//    vis[u] = true;
//
//    int size = 0;//记录子树的最大重量
//    int sum = 1;//记录以u为子树的节点数
//
//    for (int i = h[u]; i != -1; i = e[i].ne)
//    {
//        int j = e[i].node;
//        if (vis[j])continue;
//
//        int s = dfs(j);//记录以j为子节点的子树大小
//        size = max(size, s);
//        sum += s;
//    }
//
//    //这里是更新答案的地方
//    size = max(size, n - sum); //考虑“父方向”的剩余节点
//
//    if (size < MaxSonWeight)
//    {
//        MaxSonWeight = size;
//        ans.clear();
//        ans.push_back(u);
//    }
//    else if (size == MaxSonWeight)
//    {
//        ans.push_back(u);
//    }
//
//    return sum;
//}
//
//// 新增一个DFS，用于计算从节点u出发到所有其他节点的距离总和
//void dfs_dist(int u, int d)
//{
//    vis[u] = true;
//    y += d; // 累加当前深度
//
//    for (int i = h[u]; i != -1; i = e[i].ne)
//    {
//        int j = e[i].node;
//        if (vis[j]) continue;
//        dfs_dist(j, d + 1);
//    }
//}
//
//int main()
//{
//    //预处理
//    memset(h, -1, sizeof(h));
//    cin >> n;
//    int a, b;
//
//    for (int i = 1; i <= n - 1; i++)
//    {
//        cin >> a >> b;
//        add(a, b);
//        add(b, a);
//    }
//
//    dfs(1); // 第一遍DFS，找到所有重心（存储在ans中）
//
//    // 输出答案
//    sort(ans.begin(), ans.end());
//    int x = ans[0]; // 题目要求编号最小的那个点
//
//    // 重置vis数组，用于第二遍DFS
//    memset(vis, 0, sizeof(vis));
//    y = 0; // 初始化距离总和
//
//    dfs_dist(x, 0); // 第二遍DFS，从重心x出发计算总距离y
//
//    cout << x << " " << y << endl;
//
//    return 0;
//}