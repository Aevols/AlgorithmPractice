//树形DP，这一段要好好练
//法一，犯了一个错误，在进行了重复递归的运算，没有动态规划的剪枝操作导致超时
//如果栈的深度过深，还可能出现栈溢出的问题，所以下面代码需要修改
// https://www.luogu.com.cn/problem/P1352
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//struct Tree
//{
//    int r=0;//快乐值
//    int father=0;//父节点
//    vector<int> son;//子节点
//};
//int n;
//Tree node[6005];
//int dfs(int ptr, bool state)//state为true表示选择该节点
//{   
//    //如果到最后一层节点
//    if (node[ptr].son.empty()&&state==true)return node[ptr].r;
//    if (node[ptr].son.empty() && state == false)return 0;
//    //没到最后一层节点
//    //如果选该节点，那么它的孩子只能选择不要
//    if (state == false)
//    {
//        int ans = 0;
//        for (int i : node[ptr].son)
//        {
//            ans += max(dfs(i, true), dfs(i, false));
//        }
//        return ans;
//    }
//    if (state == true)
//    {
//        int ans = node[ptr].r;
//        for (int i : node[ptr].son)
//        {
//            ans += dfs(i, false);
//        }
//        return ans;
//    }
//}
//int main()
//{
//    cin >> n;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> node[i].r;
//    }
//    //构造树
//    int l, k;
//    for (int i = 1; i < n; i++)
//    {
//        cin >> l >> k;
//        node[l].father = k;
//        node[k].son.push_back(l);
//    }
//    //找父节点
//    int point = 1;
//    while (node[point].father)
//    {
//        point = node[point].father;
//    }
//    //找到父节点开始dp
//    cout << max(dfs(point, false), dfs(point,true));;
//    return 0;
//}
//优化后代码
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//const int MAXN = 6005;
//
//struct Tree
//{
//    int r = 0;          // 快乐值
//    int parent = 0;     // 父节点 (用于找根)
//    vector<int> children; // 子节点
//
//    // dp[0]: 不邀请该职员时，以该职员为根的子树的最大快乐指数
//    // dp[1]: 邀请该职员时，以该职员为根的子树的最大快乐指数
//    int dp[2] = { 0, 0 };
//};
//
//int n;
//Tree node[MAXN];
//
//// 树形DP函数：自底向上计算 dp 状态
//void tree_dp(int u)
//{
//    // 初始化状态
//    // dp[u][0]: 不选 u，最大快乐指数从 0 开始累加
//    node[u].dp[0] = 0;
//
//    // dp[u][1]: 选 u，初始快乐指数为 u 自身的 r
//    node[u].dp[1] = node[u].r;
//
//    // 递归计算子节点，然后进行状态转移
//    for (int v : node[u].children)
//    {
//        // 1. 先递归计算子树 v 的 dp 值
//        tree_dp(v);
//
//        // 2. 状态转移（更新 u 的 dp 值）
//
//        // 状态 dp[u][0]：不选 u
//        // 子节点 v 可以选也可以不选，取 max
//        node[u].dp[0] += max(node[v].dp[0], node[v].dp[1]);
//
//        // 状态 dp[u][1]：选 u
//        // 子节点 v 只能不选
//        node[u].dp[1] += node[v].dp[0];
//    }
//}
//
//int main()
//{   
//    if (!(cin >> n)) return 0;
//    // 1. 输入快乐值 r_i
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> node[i].r;
//    }
//    // 2. 构造树（输入 n-1 条边）
//    int l, k;
//    for (int i = 1; i < n; i++)
//    {
//        if (!(cin >> l >> k)) break;
//        node[l].parent = k;
//        node[k].children.push_back(l);
//    }
//    int root = 1;
//    while (node[root].parent) 
//    {
//        root = node[root].parent;
//    }
//    // 4. 从根节点开始进行树形DP
//    tree_dp(root);
//    // 5. 输出最终结果
//    // 结果是根节点选或不选两种情况下的最大值
//    cout << max(node[root].dp[0], node[root].dp[1]) << "\n";
//
//    return 0;
//}