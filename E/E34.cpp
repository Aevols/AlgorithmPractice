//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//#include <climits> // 引入climits以使用LLONG_MAX更安全
//
//using namespace std;
//
//const int N = 1e6 + 5;
//int n, h[N];
//int cnt = 0;
//// 路径长度最大可达 10^15，long (64位) 是必须且足够的
//long d1[N], d2[N], up[N];
//int p1[N];
//
//struct Edge
//{
//    int node;
//    int ne;
//    long w; // 边权也使用 long 确保计算安全
//};
//// 边数组也要相应调整大小
//Edge e[N * 2];
//
//void add(int a, int b, long w)
//{
//    e[cnt] = { b, h[a], w };
//    h[a] = cnt++;
//}
//
//long dfs_d(int cur, int fa)
//{
//    d1[cur] = 0, d2[cur] = 0;
//    for (int i = h[cur]; i != -1; i = e[i].ne)
//    {
//        int j = e[i].node;
//        if (j == fa) continue;
//
//        // 递归计算子树 j 的最远距离，加上当前边的权值
//        long d = dfs_d(j, cur) + e[i].w;
//
//        if (d > d1[cur]) {
//            d2[cur] = d1[cur]; // 原来的 d1 降级为 d2
//            d1[cur] = d;       // 找到新的最长链 d1
//            p1[cur] = j;       // 记录 d1 来自哪个孩子
//        }
//        else if (d > d2[cur]) d2[cur] = d;
//    }
//    return d1[cur]; // 返回当前子树的最长链
//}
//
//void dfs_u(int cur, int fa)
//{
//    for (int i = h[cur]; i != -1; i = e[i].ne)
//    {
//        int j = e[i].node;
//        if (j == fa) continue;
//
//        long from_fa;
//
//        // 判断子节点 j 走的是否是当前节点 cur 的最长链 d1
//        if (p1[cur] == j)
//            // 如果 j 走了 d1，那么 j 向上看时，最远路径是 max(up[cur], d2[cur])
//            from_fa = max(up[cur], d2[cur]) + e[i].w;
//        else
//            // 如果 j 没走 d1，那么 j 向上看时，最远路径是 max(up[cur], d1[cur])
//            from_fa = max(up[cur], d1[cur]) + e[i].w;
//
//        up[j] = from_fa;
//
//        dfs_u(j, cur);
//    }
//}
//
//int main()
//{
//    // C++ 习惯使用 long long 来确保 64 位整数，这里 long 和 long long 效果一致
//    // 确保 h 数组初始化为 -1
//    memset(h, -1, sizeof(h));
//
//    // 注意：将 Edge 结构体中的 w 也改为 long，保持类型一致性
//    cin >> n;
//    long a, b, c; // 将 a, b, c 也设为 long，虽然节点编号是 int 范围，但类型一致性更好
//
//    for (int i = 1; i <= n - 1; i++)
//    {
//        cin >> a >> b >> c;
//        // add 函数参数类型相应修改
//        add(a, b, c);
//        add(b, a, c);
//    }
//
//    // 第一次 DFS：从根向下计算 d1 和 d2
//    dfs_d(1, 0);
//
//    // 第二次 DFS：从根向上计算 up
//    dfs_u(1, 0);
//
//    // 使用 LLONG_MAX 或一个明确的巨大数字初始化，保证安全
//    // LLONG_MAX 是 long long 类型的最大值
//    long min_max = LLONG_MAX;
//    vector<int> centers;
//
//    // 遍历所有节点，找最小离心率
//    for (int cur = 1; cur <= n; cur++)
//    {
//        // cur 的离心率 (最大距离) 是 max(向下最长, 向上最长)
//        long max_dist = max(d1[cur], up[cur]);
//
//        if (max_dist < min_max)
//        {
//            min_max = max_dist;
//            centers.clear();
//            centers.push_back(cur);
//        }
//        else if (max_dist == min_max)
//        {
//            centers.push_back(cur);
//        }
//    }
//
//    // 按要求从小到大排序并输出
//    sort(centers.begin(), centers.end());
//    for (int node : centers)
//    {
//        cout << node << endl;
//    }
//
//    return 0;
//}
// 树的中心 树形DP O(n)
//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int N = 1000010;
//int n, son[N];
//long long f[N], g[N], up[N], d[N], md = 1e18;
//vector<pair<int, int>> e[N];
//vector<int> v;
//
//void dfs(int u, int fa) {
//    for (auto [v, w] : e[u]) {
//        if (v == fa) continue;
//        dfs(v, u);
//        if (f[u] < f[v] + w) g[u] = f[u], f[u] = f[v] + w, son[u] = v; //f[u]:u下方的最长距离
//        else if (g[u] < f[v] + w) g[u] = f[v] + w; //g[u]:u下方的次长距离
//    }
//}
//void dfs2(int u, int fa) {
//    for (auto [v, w] : e[u]) {
//        if (v == fa) continue;
//        if (v == son[u]) up[v] = max(up[u], g[u]) + w;
//        else up[v] = max(up[u], f[u]) + w; //up[v]:v上方的最长距离
//        dfs2(v, u);
//    }
//    d[u] = max(up[u], f[u]); //d[u]:到u的最长距离
//    md = min(md, d[u]);      //最长距离的最小值
//}
//int main() {
//    ios::sync_with_stdio(0);
//    cin >> n;
//    for (int i = 1, a, b, c; i < n; i++) {
//        cin >> a >> b >> c;
//        e[a].emplace_back(b, c);
//        e[b].emplace_back(a, c);
//    }
//    dfs(1, 0);
//    dfs2(1, 0);
//    for (int i = 1; i <= n; i++) if (d[i] == md) v.emplace_back(i);
//    for (int i : v) cout << i << "\n";
//}