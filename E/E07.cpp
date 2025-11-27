////https://www.luogu.com.cn/problem/P2758
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//
//char a[2005], b[2005];
//int f[2005][2005];
//
//int main() {
//    scanf("%s %s", a, b);
//    int la = strlen(a), lb = strlen(b);
//    for (int i = 1; i <= la; i++) f[i][0] = i;
//    for (int i = 1; i <= lb; i++) f[0][i] = i;
//    for (int i = 1; i <= la; i++)
//        for (int j = 1; j <= lb; j++)
//            if (a[i - 1] == b[j - 1])f[i][j] = f[i - 1][j - 1];
//            else f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
//
//    printf("%d\n", f[la][lb]);
//}