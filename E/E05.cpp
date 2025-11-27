////https://www.luogu.com.cn/problem/U197280
//#include <iostream>
//#include <string>
//#include <vector>
//#include<memory>
//#define N 205
//
//using namespace std;
//string s1, s2;
//int f[N][N];
//
//int main()
//{
//    cin >> s1>>s2;
//    int n = s1.size();
//    int m = s2.size();
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            if (s1[i-1] == s2[j-1])
//            {
//                f[i][j] = f[i-1][j-1] + 1;
//                          //max(f[i - 1][j], f[i][j - 1])+1注意，不能用这个，当我们考虑baaab和babc时
//                          //这时f[3][2]应该是2，但是因为f[2][2]也为2，f[3][1]为1我们会得出f[3][2]=f[2][2]+1
//                          //为3的情况超算了，大概就是这个意思
//            }
//            else
//            {
//                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
//            }
//        }
//    }
//    cout << f[n][m];
//    return 0;
//}

////https://www.luogu.com.cn/problem/P2516
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//
//
//    return 0;
//}
//


//https://www.luogu.com.cn/problem/P1439

//当输入的两个序列都是 1 到 N 的排列时，LCS 问题可以等价地转化为最长上升子序列（LIS）问题
//这道题非常的关键，理解了这道题今天任务就算完成
//我们要找一个子序列s，它既是P1的子序列，又是P2的子序列，当特殊情况P1是个单调递增的序列时，我们只要保证
//P2的子序列是单调上升的就可以了，这时问题就是lis了，lis我们有二分加贪心算法，然而，一般情况下P1都是乱序的
//我们可以将其映射在一个坐标系下，我们定义一个函数posiP1（x），将每个元素值 x映射到0它在P1中的位置
//那么它的子序列在这个坐标系下一定是递增的，接下来的问题就是将P2映射到这个坐标系下，这个时候难点又来了
//我们根据P2的顺序找到元素，如何根据posiP1的下标，再反映这个元素P1的位置，这样就得到了A
//这个A有两个特点，它的下标反映的是P2的位置，它的值反映的是P1的位置，这样我们保证了它的lis既是P1的子序列
//因为下标和P2对的上，又是P1的子序列，因为它是一个上升子序列，保证在元素在P1的位置是上升的。

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring> // 包含 memset 等
//
//using namespace std;
//
//// N_MAX 只需要是 N 的上限
//const int N_MAX = 100005;
//
//// P1 的位置映射：pos[x] 存储元素 x 在 P1 中的索引（1-based）
//int pos[N_MAX];
//// LIS 算法的辅助数组：b[i] 存储长度为 i 的 LIS 的最小末尾值
//int b[N_MAX];
//int main()
//{
//    int n;
//    if (!(cin >> n)) return 0;
//
//    // --- 步骤一：创建 P1 的位置映射 (pos) ---
//    // P1 中的元素 x 放在 i 位置
//    for (int i = 1; i <= n; i++)
//    {
//        int x;
//        cin >> x;
//        // 记录元素 x 在 P1 中的位置为 i
//        pos[x] = i;
//    }
//    // --- 步骤二：创建 LIS 目标序列 A 并求解 LIS ---
//
//   // len: 当前最长上升子序列的长度
//    int len = 0;
//    // 遍历 P2 的元素 (x)，构建 LIS 目标序列 A
//    for (int i = 1; i <= n; i++)
//    {
//        int x;
//        cin >> x; // x 是 P2 中的当前元素
//        int a_i = pos[x];
//
//        // LIS 算法的核心贪心和二分
//
//        // 1. 如果 a_i 大于当前最长 LIS 的末尾
//        if (a_i > b[len])
//        {
//            // 延长 LIS
//            b[++len] = a_i;
//        }
//        else
//        {
//            // 2. 查找 b 中第一个大于等于 a_i 的位置 m
//            // 使用 std::lower_bound 查找（在 [b+1, b+len+1) 范围内）
//            // 注意：b[0] 留空或作为哨兵，实际范围从 b[1] 开始
//            int m = lower_bound(b + 1, b + len + 1, a_i) - b;
//
//            // 替换 b[m]：用更小的 a_i 优化长度为 m 的 LIS
//            b[m] = a_i;
//        }
//    }
//
//    // --- 步骤三：输出结果 ---
//    // LIS 的长度就是两个排列的 LCS 的长度
//    cout << len << "\n";
//
//    return 0;
//}
