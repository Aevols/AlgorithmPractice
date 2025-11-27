////https://www.luogu.com.cn/problem/P2704
////这道题难度相对于前两题，我认为难度会更大一点
//#include <iostream>
//#include <string>
//#include <vector>
//#include<algorithm>
//using namespace std;
//int n, m;
//int map[105];//地图,1_based
//int states[1 << 12];//状态,0_based
//int num[1 << 12];//该状态下有多少个炮台,0_based
//int cnt = 0;//有多少种状态
//int dp[105][70][70];//左移12位超内存了，确实很容易超内存，但是这样也超内存了，之后我们用滚动数组代替
//int main()
//{
//    cin >> n >> m;
//    //存放地图
//    for (int i = 1; i <= n; i++)
//    {
//        string s;
//        cin >> s;
//        reverse(s.begin(), s.end());
//        int a=0;
//        for (int j = 0; j < m; j++)
//        {
//            if (s[j] == 'P')
//                a += (1 << j);
//        }
//        map[i] = a;
//        //cout << a << endl;//没问题
//    }
//    //存放合法状态
//    for (int i = 0; i < (1 << m); i++)
//    {
//        if (!(i & i >> 1) && !(i & i >> 2))
//        {
//            states[cnt] = i;
//            for (int j = 0; j < m; j++)
//            {
//                if (1 & i >> j)num[cnt]++;
//            }
//            cnt++;
//        }    
//    }
//    //以上预处理完成，开始dp
//    for (int i = 1; i <= n + 2; i++) //枚举行
//        for (int a = 0; a < cnt; a++)  //枚举第i行合法状态
//            for (int b = 0; b < cnt; b++)  //枚举第i-1行合法状态
//                for (int c = 0; c < cnt; c++)  //枚举第i-2行合法状态
//                    if (!(states[a] & states[b]) && !(states[a] & states[c]) && !(states[b] & states[c])
//                        && (map[i] & states[a]) == states[a] && (map[i - 1] & states[b]) == states[b])
//                        dp[i][a][b] = max(dp[i][a][b], dp[i - 1][b][c] + num[a]);
//    cout << dp[n + 2][0][0] << endl;
//    return 0;
//}
//滚动数组方法
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//const int N = 110, M = 1 << 10;
//int n, m;    //行数,列数 
//int g[N];   //存储地图各行数值
//int cnt;    //一行的合法状态个数
//int s[M];   //一行的合法状态集 
//int num[M]; //每个合法状态包含1的个数 
//int f[2][M][M]; //滚动数组 2*1024*1024*4 = 8MB
//// f[i][a][b]表示已放好前i行，
//// 第i行第a个状态，第i-1行第b个状态时，能放置的最大数量 
//
//int main() {
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++)
//        for (int j = 0; j < m; j++) {
//            char c; cin >> c;
//            if (c == 'P') g[i] += 1 << (m - j - 1); //地图各行数值          
//        }
//
//    for (int i = 0; i < (1 << m); i++)   //枚举一行的所有状态 
//        if (!(i & i >> 1) && !(i & i >> 2)) { //如果不存在11和101 
//            s[cnt++] = i;               //保存一行的合法状态
//            for (int j = 0; j < m; j++)
//                num[i] += (i >> j & 1);         //每个合法状态包含1的个数
//        }
//
//    for (int i = 1; i <= n + 2; i++) //枚举行
//        for (int a = 0; a < cnt; a++)  //枚举第i行合法状态
//            for (int b = 0; b < cnt; b++)  //枚举第i-1行合法状态
//                for (int c = 0; c < cnt; c++)  //枚举第i-2行合法状态
//                    if (!(s[a] & s[b]) && !(s[a] & s[c]) && !(s[b] & s[c])
//                        && (g[i] & s[a]) == s[a] && (g[i - 1] & s[b]) == s[b])
//                        f[i & 1][a][b] = max(f[i & 1][a][b], f[i - 1 & 1][b][c] + num[s[a]]);
//
//    cout << f[n + 2 & 1][0][0] << endl;
//    return 0;
//}