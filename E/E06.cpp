//https://www.luogu.com.cn/problem/T493246
//#include<bits/stdc++.h>
//using namespace std;
//
//const int N = 1005;
//char a[N], b[N];
//int n, m, f[N][N], ans;
//
//int main() {
//    cin >> a + 1 >> b + 1;
//    n = strlen(a + 1); m = strlen(b + 1);
//
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
//            if (f[i][j] > ans) ans = f[i][j];
//        }
//    }
//    cout << ans << "\n";
//    return 0;
//}



//https://www.luogu.com.cn/problem/U396793
//#include<bits/stdc++.h>
//using namespace std;
//
//const int N = 1005;
//char a[N], b[N];
//int n, m, f[N][N], ans, pos;
//
//int main() {
//    cin >> a + 1 >> b + 1;
//    n = strlen(a + 1); m = strlen(b + 1);
//
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
//            if (f[i][j] > ans) ans = f[i][j], pos = i;
//        }
//    }
//    cout << ans << "\n";
//    for (int i = pos - ans + 1; i <= pos; i++) cout << a[i];
//    return 0;
//}

////https://www.luogu.com.cn/problem/P5546
////这里我们使用二分答案+字符串哈希
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//
//// --- 字符串哈希参数 (双哈希) ---
//// 第一组哈希参数
//const long long P1 = 31;            // 基数 1
//const long long M1 = 1e9 + 7;       // 模数 1
//// 第二组哈希参数
//const long long P2 = 131;           // 基数 2
//const long long M2 = 1e9 + 9;       // 模数 2
//
//// 存储所有字符串
//vector<string> words;
//// 存储每个单词的前缀哈希
////从右往左读，第一个longlong是说哈希值是longlong类型的
//vector<vector<long long>> H1; // H1[i][j] 存储第 i 个单词的前 j 个字符的哈希 1
//vector<vector<long long>> H2; // H2[i][j] 存储第 i 个单词的前 j 个字符的哈希 2
//// P 的幂次
//vector<long long> P_pow1;
//vector<long long> P_pow2;
//
//int N; // 单词数量
//int max_len; // 最长单词的长度
//
//// 初始化哈希所需的预计算数据
//void init_hash() 
//{
//    max_len = 0;
//    for (const auto& w : words) 
//    {
//        max_len = max(max_len, (int)w.length());
//    }
//
//    // 预计算 P 的幂次
//    P_pow1.resize(max_len + 1);
//    P_pow2.resize(max_len + 1);
//    P_pow1[0] = P_pow2[0] = 1;
//    for (int i = 1; i <= max_len; i++) 
//    {
//        P_pow1[i] = (P_pow1[i - 1] * P1) % M1;
//        P_pow2[i] = (P_pow2[i - 1] * P2) % M2;
//    }
//
//    // 预计算前缀哈希
//    H1.resize(N);
//    H2.resize(N);
//
//    for (int i = 0; i < N; i++) 
//    {
//        const string& w = words[i];
//        int len = w.length();
//        H1[i].resize(len + 1, 0);
//        H2[i].resize(len + 1, 0);
//
//        for (int j = 0; j < len; j++) 
//        {
//            // H[i] = (H[i-1] * P + w[j]) % M//朴素哈希计算方法
//            H1[i][j + 1] = (H1[i][j] * P1 + (w[j] - 'a' + 1)) % M1;
//            H2[i][j + 1] = (H2[i][j] * P2 + (w[j] - 'a' + 1)) % M2;//这里必须要进位
//        }
//    }
//}
//
//// O(1) 获取子串 w[l..r] 的哈希值 (l, r 是 1-based 索引)
//pair<long long, long long> get_hash(int word_idx, int l, int r) 
//{
//    long long h1, h2;
//    int len = r - l + 1;
//
//    // H[r] - H[l-1] * P^len
//
//    // Hash 1//哈希计算算法
//    h1 = (H1[word_idx][r] - (H1[word_idx][l - 1] * P_pow1[len]) % M1 + M1) % M1;
//
//    // Hash 2
//    h2 = (H2[word_idx][r] - (H2[word_idx][l - 1] * P_pow2[len]) % M2 + M2) % M2;//这里也必须要进位，为了抵消位数不同带来的影响
//
//    return { h1, h2 };
//}
//
//// 判定函数：检查是否存在长度为 L 的公共子串
//bool check(int L) 
//{
//    if (L == 0) return true;
//
//    // 1. 收集第一个单词 W_0 的所有长度为 L 的子串哈希
//    vector<pair<long long, long long>> common_hashes;
//    int len0 = words[0].length();
//
//    // 遍历所有可能的起始位置 i (1-based)
//    for (int i = 1; i <= len0 - L + 1; i++) 
//    {                                    
//        common_hashes.push_back(get_hash(0, i, i + L - 1));
//    }
//
//    // 2. 遍历后续单词，并不断求交集
//    for (int i = 1; i < N; i++) 
//    {
//        const string& w = words[i];
//        int len_i = w.length();
//
//        // 临时集合，存储 W_i 和 common_hashes 的交集
//        vector<pair<long long, long long>> temp_hashes;
//
//        // 优化：将 common_hashes 排序，方便二分查找
//        sort(common_hashes.begin(), common_hashes.end());
//
//        // 遍历 W_i 的所有长度为 L 的子串
//        for (int j = 1; j <= len_i - L + 1; j++) 
//        {
//            pair<long long, long long> h = get_hash(i, j, j + L - 1);
//
//            // 使用二分查找/lower_bound 检查 h 是否在 common_hashes 中
//            if (binary_search(common_hashes.begin(), common_hashes.end(), h)) 
//            {
//                temp_hashes.push_back(h);
//            }
//        }
//
//        // 更新 common_hashes 为交集 (temp_hashes)
//        common_hashes = temp_hashes;
//
//        // 如果交集为空，说明不存在公共子串，直接返回 false
//        if (common_hashes.empty()) 
//        {
//            return false;
//        }
//    }
//
//    // 3. 所有单词都遍历完，交集非空，存在长度为 L 的公共子串
//    return true;
//}
//
//int main() 
//{
//   
//    if (!(cin >> N)) return 0;
//    words.resize(N);
//    for (int i = 0; i < N; i++) 
//    {
//        cin >> words[i];
//    }
//
//    // 预处理哈希
//    init_hash();
//
//    // --- 二分查找 ---
//    int L = 0;             // 最短长度 0
//    int R = max_len;       // 最长长度 2000
//    int max_LCS_len = 0;
//
//    while (L <= R) 
//    {
//        int mid = L + (R - L) / 2;
//
//        if (check(mid)) 
//        {
//            max_LCS_len = mid; // mid 是可行的答案
//            L = mid + 1;       // 尝试更大的长度
//        }
//        else 
//        {
//            R = mid - 1;       // mid 不可行，缩小范围
//        }
//    }
//
//    cout << max_LCS_len << "\n";
//
//    return 0;
//}
