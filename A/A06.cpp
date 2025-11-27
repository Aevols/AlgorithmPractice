////P2440,二分做的确实差。//由于A06题目太多，所以我们有时间再来继续，我们先跳到贪心
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int n, k;
//vector<int> length;
//int get_section(int size)
//{
//	long section = 0;
//	for (int i : length)
//	{
//		section += (i / size);
//		if (section > k) return section;//为防止越界，超过k段我们就退出
//	}
//	return section;
//}
//int main()
//{
//	int len;
//	cin >> n >> k;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> len;
//		length.push_back(len);
//	}
//	//左边l一定要保持在可行区内
//	int l = 0, r = 1000000005;
//	int mid;
//	while (l + 1 < r)
//	{
//		mid = (l + r) >> 1;
//		if (k > get_section(mid))r = mid;
//		else l = mid;
//	}
//	cout << l;
//	
//	return 0;
//}
////P2678，这道题我出现两个问题，一个是函数图单调性画反了，一个是丢失了起点 0 这个至关重要的距离点
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//int l, n, m;
//long long dis[50005];
//bool check(int x)//如果能通过返回true
//{   
//    int last = 0, cnt = 0;
//    for (int i = 1; i <= n+1; i++)
//    {
//        if (dis[i] - dis[last] < x)cnt++;
//        else last = i;
//    }
//    return cnt <= m;
//}
//int main() 
// {
//    cin >> l >> n >> m;
//    for (int i = 1; i <=n; i++)
//    {
//        cin >> dis[i];
//    }
//    dis[n+1] = l;//为了最后一个特殊处理
//    int l = 0, r = 1000000005;
//    int mid;
//    //二分,函数画反了，666又写错了
//    while (l + 1 < r)
//    {
//        mid = l + r >> 1;
//        if (check(mid))l = mid;
//        else r = mid;
//    }
//    cout << l;
//    return 0;
//}
//P1314
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//int n, m;
//int w[200005], v[200005];
//int le[200005], ri[200005];
//long long  sw[200005],s;
//long long  sv[200005],ans=1e18;
//long long f(int ww)
//{
//    for (int i = 1; i <= n; i++)
//    {
//        if (w[i] - ww >= 0) { sw[i] = sw[i - 1] + 1; sv[i] = sv[i - 1] + v[i]; }
//        else 
//        {
//            sw[i] = sw[i - 1]; sv[i] = sv[i - 1];
//        }
//    }
//    long long y = 0;
//    for (int i = 1; i <= m; i++)
//    {
//        y += (sw[ri[i]] - sw[le[i] - 1]) * (sv[ri[i]] - sv[le[i] - 1]);
//    }
//    return y;
//}
//int main() 
//{  
//    cin >> n >> m >> s;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> w[i] >> v[i];
//    }
//    for (int i = 1; i <= m; i++)
//    {
//        cin >> le[i] >> ri[i];
//    }
//
//    long long l = 0, r = 1000001;
//    long long mid;
//    while (l + 1 < r)
//    {   
//        mid = l + r >> 1;
//        if (f(mid) <= s)r = mid;
//        else l = mid;
//    }
//    cout << min(f(l) - s, s - f(r));
//    return 0;
//}



//P1083//666代码需求写错了，写成了第几天订单不够，但是具体思路学会了，直接看董老师代码吧
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int n, m;
//vector<long> r(1e6+ 5);
//vector<long> d(1e6 + 5);
//vector<int> s(1e6 + 5);
//vector<int> e(1e6 + 5);
//vector<long long> reques(1e6 + 5, 0);
//
//bool check(int c)
//{
//    for (int i = 1; i <= c; i++)
//    {
//        if (reques[i] > r[i])return false;
//    }
//    return true;
//}
//int main()
//{
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> r[i];
//    }
//    //差分
//    for (int i = 1; i <= m; i++)
//    {
//        cin >> d[i]>>s[i]>>e[i];
//        //记录这个订单对预期产生了什么样的影响
//        reques[s[i]] += d[i];
//        reques[e[i] + 1] -= d[i];
//    }
//    //差分归并
//    for (int i = 1; i <= n + 1; i++)
//    {
//        reques[i] += reques[i - 1];
//    }
//    if (check(m))cout << "0";
//    else
//     //二分逻辑
//    {
//        int l = 0, r = n + 1,mid;
//        while (l + 1 < r)
//        {
//            mid = l + r >> 1;
//            if (check(mid))l = mid;
//            else r = mid;
//        }
//        cout <<-1<<endl<< r;
//    }
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//
//const int N = 1000010;
//int n, m, r[N], d[N], s[N], t[N];
//long long num[N]; //每天教室需求数
//
//bool check(int x) {
//    memset(num, 0, sizeof num);
//    for (int i = 1; i <= x; i++) {//枚举订单数
//        num[s[i]] += d[i];
//        num[t[i] + 1] -= d[i]; //差分
//    }
//    for (int i = 1; i <= n; i++) {//枚举天数
//        num[i] += num[i - 1]; //前缀和
//        if (num[i] > r[i])return false;
//    }
//    return true;
//}
//int main() {
//    scanf("%d%d", &n, &m);
//    for (int i = 1; i <= n; i++)scanf("%d", &r[i]);
//    for (int i = 1; i <= m; i++)scanf("%d%d%d", &d[i], &s[i], &t[i]);
//    if (check(m)) { puts("0"); return 0; }
//
//    int l = 0, r = m + 1;
//    while (l + 1 < r) {
//        int mid = l + r >> 1;
//        if (check(mid)) l = mid; //最大化
//        else r = mid;
//    }
//    printf("-1\n%d", l + 1); //匹配失败的订单
//    return 0;
//}

//P1902这道题是走迷宫的强化版，bfs得用队列来实现
 
 
 
//#include<iostream>
//#include<queue>
//#include<cstring> // 引入 cstring 用于 memset
//#include<utility> // 引入 utility 用于 pair
//#include<algorithm> // 引入 algorithm 用于 max
//
//#define N 1005
//using namespace std;
//
//int n, m;
//int l = -1, r = 1001; // 初始化 r 可以更大，例如 1001，但最好使用实际的最大伤害值
//int market[N][N];
//bool path[N][N]; // 更改名称为 path，并改为 bool 类型，用于记录在 check(mid) 中的可达性
//
//// 四个方向：上、下、左、右
//int dr[] = { -1, 1, 0, 0 };
//int dc[] = { 0, 0, -1, 1 };
//
//bool check(int mid) {
//    for (int i = 0; i < n; i++) {
//        memset(path[i], 0, sizeof(bool) * m);
//    }
//
//    queue<pair<int, int>> q; // 存储 (row, col)
//
//    // 起点入队：第 0 行的所有房间
//    for (int j = 0; j < m; j++) {
//        q.push({ 0, j });
//        path[0][j] = true;
//    }
//
//    // BFS 搜索
//    while (!q.empty()) {
//        pair<int, int> curr = q.front();
//        q.pop();
//        int r = curr.first;
//        int c = curr.second;
//
//        // 遍历四个邻居
//        for (int i = 0; i < 4; i++) {
//            int nr = r + dr[i];
//            int nc = c + dc[i];
//
//            // 检查边界
//            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
//                // 检查是否已访问
//                if (!path[nr][nc]) {
//                    // 检查伤害值是否超过 mid (障碍判断)
//                    if (market[nr][nc] <= mid) {
//                        path[nr][nc] = true;
//                        q.push({ nr, nc });
//                    }
//                }
//            }
//        }
//    }
//
//    // 检查结果：第 n-1 行的所有房间是否都被访问
//    for (int j = 0; j < m; j++) {
//        if (!path[n - 1][j]) {
//            return false; // 只要有一个机关不可达，就失败
//        }
//    }
//
//    return true; // 所有机关都可达
//}
//
//int main()
//{
//
//    cin >> n >> m;
//    int max_p = 0;
//
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//        {
//            cin >> market[i][j];
//            max_p = max(max_p, market[i][j]);
//        }
//
//    // 重新设置二分边界，更精确
//    l = -1; // 最小伤害值下界 - 1
//    r = max_p + 1; // 最大伤害值上界 + 1
//
//    int mid;
//    while (l + 1 < r)
//    {
//        mid = l + r >> 1;
//        if (check(mid)) r = mid; // mid 是可行解，尝试更小的
//        else l = mid;           // mid 不可行，提高下界
//    }
//
//    cout << r;
//    return 0;
//}


//P1824，贪心就可以了,记得特别注意<和<=,第二点check函数漏了最后一次加牛的条件判断，这在牛刚好是m个的时候出现返回false的情况，自己以前也经常犯这样的错误

//#include <iostream>
//#include <string>
//#include <vector>
//#include<algorithm>
//
//using namespace std;
//int n, m;
//vector<int> sherd;
//vector<int> interval;
//
//bool check(int mid)
//{
//    int bull = 1;
//    int space = 0;
//    for (int i : interval)
//    {
//        if (bull >= m)return true;
//        space += i;
//        if (space >= mid)
//        {
//            bull++;
//            space = 0;
//        }
//        
//    }
//    return bull>=m;
//}
//
//int main()
//{   
//    cin >> n >> m;
//    int posi = 0;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> posi;
//        sherd.push_back(posi);
//    }
//    sort(sherd.begin(),sherd.end());
//    for (int i = 0; i < n-1; i++)
//    {
//        posi = sherd[i + 1] - sherd[i];
//        interval.push_back(posi);
//    }
//    int l = *min_element(interval.begin(), interval.end()), r = 1e9 + 1;
//    int mid = 0;
//    while (l + 1 < r)
//    {
//        mid = l + r >> 1;
//        if (check(mid))l = mid;
//        else r = mid;
//    }
//    cout << l;
//    return 0;
//}


//P7333
//思路：首先我先想对于一个节点i，我如果找到了一个节点j满足aj≥bi的条件，
// 那么对于这两点之间的距离就是min(abs(i-j),n-abs(i-j)),那么接下来的关键就是怎么找这个节点j了，
// 我一开始的想法是定义一个结构体，将ai和它的节点号连接在一起，然后根据ai的大小进行排序，
// 通过bi大小进行二分查找，来得到满足的节点aj，这样我们就得到了满足条件aj≥bi，
// 但是这又出现了另一个问题，就是这个j节点不是最近的，不能够满足fi的定义
//那么这个时候，我只能想到我们通过二分查找找到的坐标，一路向后去查找，直到找到最后最近的，
//这样最坏的复杂比原先暴力查找还要高log2N倍，一般的情况也只比原来少了一半时间
//我这个方法必然超时，所以我们现在借鉴大佬的写法

//#include <iostream>
//#include <string>
//#include <vector>
//#include<algorithm>
//#include<math.h>
//
//using namespace std;
//
//#define N 100005
//
//class self
//{
//public:
//    int a;
//    int seq;
//    bool operator<(const self& other) const {
//        // 定义默认的升序排序规则：按属性 a 比较
//        return this->a < other.a;
//    }
//};
//
//int n;
//vector<int>B;
//vector<self> A;
//
//
//bool check(int mid, int i)
//{
//    if (B[i] <= A[mid].a)return true;
//    return false;
//}
//
//int main()
//{
//    //输入，这里没问题
//    cin >> n;
//    for (int i = 1; i <= n; i++)
//    {
//        self node;
//        node.seq = i;
//        cin >> node.a;
//        A.push_back(node);
//    }
//    sort(A.begin(), A.end());
//    for (int i = 1; i <= n; i++)
//    {
//        int data;
//        cin >> data;
//        B.push_back(data);
//    }
//    
//    for (int i =0;i<n;i++)
//    {
//        //开始二分查找
//        int l = -1, r = n;
//        //查找逻辑
//        while (l + 1 < r)
//        {
//            int mid = l + r >> 1;
//            if (check(mid,i))r = mid;
//            else l = mid;
//        }
//        //未找到输出-1，进行下一轮循环
//        if (r == n)
//        {
//            cout << -1 << " ";
//            continue;
//        }
//        //找到，直接暴力寻找最近位置，这里还有一个问题就是，我们在二分查找的时候会找到自身的情况，这个
//        //时候我们会输出错误案例直接输出n，这是不对的。
//        // 找到，进入暴力寻找最近位置
//        else
//        {
//            int ans = n;
//            bool found_valid_j = false; // 增加一个标记，看是否找到过 j != i 的点
//
//            // 从第一个满足条件的索引 r 开始遍历
//            for (int j = r; j < n; j++)
//            {
//                // A[j].seq 是 1-based 的目标点 j
//                // i+1 是 1-based 的当前点 i
//                if (A[j].seq == i + 1) continue; // 排除 j = i 的情况
//
//                // 找到了 j != i 的点
//                found_valid_j = true;
//
//                // 计算环形距离
//                int distance = min(abs((i + 1) - A[j].seq), n - abs((i + 1) - A[j].seq));
//                if (distance < ans) ans = distance;
//            }
//
//            // 根据标记输出结果
//            if (found_valid_j)cout << ans << " ";
//            else cout << -1 << " ";
//            
//        }
//    }
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <climits> // For INT_MAX
//
//using namespace std;
//
//// 使用 0-based 索引，与 C++ vector 习惯保持一致
//struct Point {
//    int a;
//    int index; // 原始索引 i (0-based)
//    bool operator<(const Point& other) const {
//        return a < other.a;
//    }
//};
//
//// PST 节点定义
//struct Node {
//    int count; // 当前子树中点的数量
//    int lch, rch; // 左右子节点索引
//};
//
//const int MAXN = 100005;
//const int MAX_PST_NODES = MAXN * 20; // 经验值，N * logN
//
//Node pst_nodes[MAX_PST_NODES];
//int pst_roots[MAXN];
//int node_cnt;
//
//// 更新操作：在 pos 处加 1
//int update(int prev_node, int l, int r, int pos) {
//    int new_node = ++node_cnt;
//    pst_nodes[new_node] = pst_nodes[prev_node]; // 继承
//    pst_nodes[new_node].count++; // 数量加 1
//
//    if (l == r) return new_node;
//
//    int mid = l + r >> 1;
//    if (pos <= mid) {
//        pst_nodes[new_node].lch = update(pst_nodes[prev_node].lch, l, mid, pos);
//    }
//    else {
//        pst_nodes[new_node].rch = update(pst_nodes[prev_node].rch, mid + 1, r, pos);
//    }
//    return new_node;
//}
//
//// 查询 [ql, qr] 范围内第一个点的索引 (最小索引)
//// 两个根节点 root1 (T_n) 和 root2 (T_r)
//int query_min_index(int root1, int root2, int l, int r, int ql, int qr) {
//    if (ql > r || qr < l || root1 == 0 || root1 == root2) return -1;
//    ql = max(ql, l);
//    qr = min(qr, r);
//    if (ql > qr) return -1;
//
//    // 区间完全重合
//    if (ql == l && qr == r) {
//        if (pst_nodes[root1].count - pst_nodes[root2].count <= 0) return -1;
//        // 寻找第一个点：向左子树搜索
//        if (pst_nodes[root1].lch != pst_nodes[root2].lch) { // 左子树有差异
//            int res = query_min_index(pst_nodes[root1].lch, pst_nodes[root2].lch, l, l + r >> 1, ql, qr);
//            if (res != -1) return res;
//        }
//        // 左子树没有或无差异，向右子树搜索
//        return query_min_index(pst_nodes[root1].rch, pst_nodes[root2].rch, (l + r >> 1) + 1, r, ql, qr);
//    }
//
//    int mid = l + r >> 1;
//    int res = query_min_index(pst_nodes[root1].lch, pst_nodes[root2].lch, l, mid, ql, qr);
//    if (res != -1) return res;
//    return query_min_index(pst_nodes[root1].rch, pst_nodes[root2].rch, mid + 1, r, ql, qr);
//}
//
//// 查询 [ql, qr] 范围内最后一个点的索引 (最大索引) - 逻辑与 query_min_index 相反
//int query_max_index(int root1, int root2, int l, int r, int ql, int qr) {
//    if (ql > r || qr < l || root1 == 0 || root1 == root2) return -1;
//    ql = max(ql, l);
//    qr = min(qr, r);
//    if (ql > qr) return -1;
//
//    if (ql == l && qr == r) {
//        if (pst_nodes[root1].count - pst_nodes[root2].count <= 0) return -1;
//
//        // 寻找最后一个点：向右子树搜索
//        if (pst_nodes[root1].rch != pst_nodes[root2].rch) { // 右子树有差异
//            int res = query_max_index(pst_nodes[root1].rch, pst_nodes[root2].rch, (l + r >> 1) + 1, r, ql, qr);
//            if (res != -1) return res;
//        }
//        // 右子树没有或无差异，向左子树搜索
//        return query_max_index(pst_nodes[root1].lch, pst_nodes[root2].lch, l, l + r >> 1, ql, qr);
//    }
//
//    int mid = l + r >> 1;
//    int res = query_max_index(pst_nodes[root1].rch, pst_nodes[root2].rch, mid + 1, r, ql, qr);
//    if (res != -1) return res;
//    return query_max_index(pst_nodes[root1].lch, pst_nodes[root2].lch, l, mid, ql, qr);
//}
//
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int n;
//    cin >> n;
//
//    vector<Point> A(n);
//    vector<int> B(n);
//
//    for (int i = 0; i < n; i++) {
//        cin >> A[i].a;
//        A[i].index = i;
//    }
//    for (int i = 0; i < n; i++) {
//        cin >> B[i];
//    }
//
//    // 1. 排序
//    sort(A.begin(), A.end());
//
//    // 2. 构造 PST
//    // 索引范围 [0, n-1]
//    pst_roots[0] = 0;
//    for (int i = 0; i < n; i++) {
//        pst_roots[i + 1] = update(pst_roots[i], 0, n - 1, A[i].index);
//    }
//    // pst_roots[r] 存储了 A[0]...A[r-1] 的原始索引
//
//    for (int i = 0; i < n; i++) { // 当前点 i (0-based)
//        // 3. 二分查找第一个 A[r].a >= B[i] 的 r
//        int l = 0, r = n; // [l, r) 搜索
//        while (l < r) {
//            int mid = l + r >> 1;
//            if (A[mid].a >= B[i]) r = mid;
//            else l = mid + 1;
//        }
//        int first_r = r;
//
//        // 如果 first_r == n, 表示没有满足条件的 j
//        if (first_r == n) {
//            cout << -1 << (i == n - 1 ? "" : " ");
//            continue;
//        }
//
//        // 我们需要查询的集合 P_{first_r} 对应于 pst_roots[n] - pst_roots[first_r]
//        int min_dist = n;
//        bool found = false;
//
//        // 环形距离，只考虑距离 d <= n/2 的点 j
//        int max_dist = n / 2;
//
//        // 4.1. 顺时针方向：i+1 到 i+max_dist
//        int ql1 = (i + 1) % n;
//        int qr1 = (i + max_dist) % n;
//
//        // 绕环和不绕环分开处理
//        if (ql1 <= qr1) { // 不绕环，如 1->2...5 (n=5)
//            // 查找 [ql1, qr1] 中的最小索引 j
//            int j = query_min_index(pst_roots[n], pst_roots[first_r], 0, n - 1, ql1, qr1);
//            if (j != -1) {
//                // j 满足条件 A[j].a >= B[i] 且 j != i
//                min_dist = min(min_dist, abs(i - j));
//                found = true;
//            }
//        }
//        else { // 绕环，如 4->5->0->1 (n=5)
//            // 查找 [ql1, n-1] 中的最小索引 j1
//            int j1 = query_min_index(pst_roots[n], pst_roots[first_r], 0, n - 1, ql1, n - 1);
//            if (j1 != -1) {
//                min_dist = min(min_dist, abs(i - j1));
//                found = true;
//            }
//            // 查找 [0, qr1] 中的最小索引 j2
//            int j2 = query_min_index(pst_roots[n], pst_roots[first_r], 0, n - 1, 0, qr1);
//            if (j2 != -1) {
//                // 此时 j2 一定是绕环的，距离是 n - i + j2
//                min_dist = min(min_dist, n - abs(i - j2));
//                found = true;
//            }
//        }
//
//        // 4.2. 逆时针方向：i-1 到 i-max_dist
//        int ql2 = (i - max_dist + n) % n;
//        int qr2 = (i - 1 + n) % n;
//
//        if (ql2 <= qr2) { // 不绕环
//            // 查找 [ql2, qr2] 中的最大索引 j
//            int j = query_max_index(pst_roots[n], pst_roots[first_r], 0, n - 1, ql2, qr2);
//            if (j != -1) {
//                min_dist = min(min_dist, abs(i - j));
//                found = true;
//            }
//        }
//        else { // 绕环
//            // 查找 [0, qr2] 中的最大索引 j1
//            int j1 = query_max_index(pst_roots[n], pst_roots[first_r], 0, n - 1, 0, qr2);
//            if (j1 != -1) {
//                min_dist = min(min_dist, abs(i - j1));
//                found = true;
//            }
//            // 查找 [ql2, n-1] 中的最大索引 j2
//            int j2 = query_max_index(pst_roots[n], pst_roots[first_r], 0, n - 1, ql2, n - 1);
//            if (j2 != -1) {
//                // 此时 j2 一定是绕环的，距离是 n - j2 + i
//                min_dist = min(min_dist, n - abs(i - j2));
//                found = true;
//            }
//        }
//
//        if (found) {
//            cout << min_dist << (i == n - 1 ? "" : " ");
//        }
//        else {
//            cout << -1 << (i == n - 1 ? "" : " ");
//        }
//    }
//    cout << endl;
//
//    return 0;
//}
