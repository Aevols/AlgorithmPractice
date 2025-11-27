////P4309还是超时，只能以后再来写了，还是得用线段树
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//// 使用全局变量存储序列和长度
//int n;
//vector<int> ar;
//
//// 辅助函数：计算当前序列的最长上升子序列 (LIS) 长度
//int calculate_lis(const vector<int>& current_ar)
//{
//    // LIS 长度
//    int current_len = 0;
//    // b 数组存储长度为 i 的上升子序列的最小末尾元素
//    vector<int> b(current_ar.size() + 1, 0);
//
//    // 遍历序列中的每个元素
//    for (int num : current_ar)
//    {
//        // 如果当前元素比最长的 LIS 结尾还大，则 LIS 长度加 1
//        if (num > b[current_len])
//        {
//            b[++current_len] = num;
//        }
//        else
//        {
//            // 二分查找 b 中第一个大于等于 num 的位置
//            // 使用 std::lower_bound 查找
//            auto it = lower_bound(b.begin() + 1, b.begin() + current_len + 1, num);
//            *it = num; // 替换
//        }
//    }
//    return current_len;
//}
//
//int main()
//{
//    // 读入 N
//    cin >> n;
//
//    // 循环 N 次插入操作
//    for (int k = 1; k <= n; k++)
//    {
//        int X_k; // 插入的位置 (0-based)
//        cin >> X_k;
//
//        // 将数字 k 插入到位置 X_k
//        // k 从 1 到 N 递增
//        ar.insert(ar.begin() + X_k, k);
//
//        // 计算并输出当前序列的最长上升子序列长度
//        int lis_len = calculate_lis(ar);
//        cout << lis_len << "\n";
//    }
//
//    return 0;
//}


////B3637
//#include <iostream>
//#include <string>
//#include <vector>
//#define N 100005
//
//int n,len=1;
//int a[N];
//int b[N];
//
//using namespace std;
//
//int find(int num)
//{
//    int l = 0, r = len + 1;
//    while (l + 1 < r)
//    {
//        int mid = l + r >> 1;
//        if (b[mid] >= num)r = mid;
//        else l = mid;
//    }
//    return r;
//}
//
//
//int main()
//{
//    cin >> n;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> a[i];
//    }
//    //初始化
//    b[len] = a[len];
//    for (int i = 2; i <= n; i++)
//    {
//        if (a[i] > b[len])b[++len] = a[i];
//        else
//        {
//            int x = find(a[i]);
//            b[x] = a[i];
//        }
//    }
//    cout << len;
//    return 0;
//}
