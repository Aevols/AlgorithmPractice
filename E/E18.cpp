////有依赖的背包问题
//#include <iostream>
//#include <string>
//#include <vector>
//const int N = 105;
//using namespace std;
//int n, m;//物品数量和背包容量
//int root;//指向根节点
//int a[N][N];//邻接表储存子节点
//int b[N],w[N],v[N];//表示一个节点有多少子节点,w表示这个节点的重量,v表示价值
//int dp[N][N];//第一维数据表示以哪个节点为根节点，第二维数据表示给这个节点分配了多少空间
//void dfs(int r)
//{
//    for (int i = w[r]; i <= m; i++)
//    {
//        dp[r][i] = v[r];//初始化，一定要选择该节点，所以加上该节点的价值
//        //这里应该是v[r],写成了v[i]
//    }
//    //
//    for (int i = 1; i <= b[r]; i++)
//    {
//        int s = a[r][i];//s是r的第i个节点
//        dfs(s);//先求出儿子最好的选法
//        for (int j = m; j >= w[r]; j--)//体积
//        {
//            for (int k = 0; k <= j - w[r]; k++)//给儿子分配的体积
//            {
//                dp[r][j] = max(dp[r][j], dp[r][j - k] + dp[s][k]);
//            }
//        }
//    }
//}
//int main()
//{
//    cin >> n >> m;
//    int node;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> w[i] >> v[i] >> node;
//        //父节点特殊处理
//        if (node == -1)
//        {
//            root = i;//这里写成了root=node
//            continue;
//        }
//        a[node][++b[node]] = i;//更新父节点有哪些子节点，并更新子节点的个数
//    }
//    //动态规划逻辑（分组背包+树形dp）
//    dfs(root);
//    cout << dp[root][m];
//    return 0;
//}
//https://www.lanqiao.cn/problems/1179/learning/?page=1&first_category_id=1&tags=%E6%A0%91%E4%B8%8A%E8%83%8C%E5%8C%85&tag_relation=intersection
//小明的背包问题可能出现多个树的情况，所以说我更改后的代码是不对的把，但是我们也可以把这个森林连接到“0”节点上，0节点的价值和花费都是0
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring> // 添加 memset
//
//using namespace std;
//
//const int MAX_ITEMS = 105;
//
//int n_items, V; // 物品数量 n_items (原题 N) 和背包容量 V (原题 M)
//int root_node; // 虚拟根节点编号
//// 数组大小需要适应 N+1 个节点
//int a[MAX_ITEMS][MAX_ITEMS]; // 邻接表储存子节点
//int b[MAX_ITEMS], w[MAX_ITEMS], v[MAX_ITEMS];
//int dp[MAX_ITEMS][MAX_ITEMS]; // dp[r][j]
//
//void dfs(int r)
//{
//    // 1. 初始化 DP 状态：强制选择节点 r
//    for (int j = 0; j <= V; j++)
//    {
//        if (j >= w[r]) {
//            dp[r][j] = v[r];
//        }
//        else {
//            dp[r][j] = 0;
//        }
//    }
//
//    // 2. 遍历 r 的所有孩子（分组背包合并）
//    for (int i = 1; i <= b[r]; i++)
//    {
//        int s = a[r][i]; // s 是 r 的第 i 个子节点
//        dfs(s);          // 先求出子树 s 的最优解
//
//        for (int j = V; j >= w[r]; j--) // 背包总容量 j，从大到小
//        {
//            // k 是分配给子树 s 的体积。
//            for (int k = 0; k <= j - w[r]; k++)
//            {
//                // 只有当分配 k 之后能获得比当前更好的价值时才更新
//                if (dp[s][k] > 0 || k == 0) // k=0 相当于不选子树 s
//                {
//                    dp[r][j] = max(dp[r][j], dp[r][j - k] + dp[s][k]);
//                }
//            }
//        }
//    }
//}
//
//int main()
//{
//    // 输入输出加速
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//
//    cin >> n_items >> V; // V 是背包容量 M
//
//    // 1. 设置虚拟根节点 N+1
//    root_node = n_items + 1;
//    w[root_node] = 0;
//    v[root_node] = 0;
//
//    for (int i = 1; i <= n_items; i++)
//    {
//        int w_i, v_i, p_i;
//        // 题目为 V, W, P
//        cin >> w_i >> v_i >> p_i;
//
//        w[i] = w_i;
//        v[i] = v_i;
//
//        if (p_i == 0 || p_i == -1) // 依赖 0 或 -1 的都是森林的根
//        {
//            // 将森林的根连接到虚拟根上
//            a[root_node][++b[root_node]] = i;
//        }
//        else // 非根节点
//        {
//            // 构建树
//            a[p_i][++b[p_i]] = i;
//        }
//    }
//
//    // 2. 动态规划逻辑：从虚拟根开始 DP
//    dfs(root_node);
//
//    // 3. 最终答案是虚拟根在容量 V 下的最大价值
//    // 由于虚拟根的体积和价值都是 0，dp[root_node][V] 包含了所有子树的组合最大值。
//    cout << dp[root_node][V] << "\n";
//
//    return 0;
//}
//https://www.luogu.com.cn/problem/P2014
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//const int N = 305;
//vector<int> e[N];
//int n, m, w[N], f[N][N], siz[N];
//
//void dfs(int u) {
//    f[u][1] = w[u]; siz[u] = 1;
//    for (int v : e[u]) {
//        dfs(v);
//        siz[u] += siz[v];
//        for (int j = min(m + 1, siz[u]); j; j--) //课程
//            for (int k = 0; k <= min(j - 1, siz[v]); k++) //决策      
//                f[u][j] = max(f[u][j], f[u][j - k] + f[v][k]);
//    }
//}
//int main() {
//    scanf("%d%d", &n, &m);
//    for (int i = 1, k; i <= n; i++) {
//        scanf("%d%d", &k, &w[i]);
//        e[k].push_back(i);
//    }
//    dfs(0); //虚拟根节点0
//    printf("%d", f[0][m + 1]);
//}