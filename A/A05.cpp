/*二分查找的思想虽然简单，但是在实际处理的过程中，边界条件的处理却是很需要细节和耐心的
自己之前在写二分法的时候也吃了很多亏，浪费了很多时间，感谢董老师对二分法的一个解答*/
//P2249
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//int arr[1000005],q,n,m;
//int find(int q)
//{   
//    int l = -1, r = n;
//    while (l + 1 < r)
//    {
//        int mid = (l + r) >> 1;
//        if (arr[mid] < q) l = mid;
//        else r = mid;
//    }
//    return arr[r] == q ? r+1 : -1;
//}
//int main() 
//{   
//
//    int i=0;
//    cin >> n >>m;
//    while (i<n)
//    {
//        cin >> arr[i++];
//    }
//    for (int i = 1; i <= m; i++)
//    {
//        cin >> q;
//        cout << find(q)<<" ";
//    }
//    return 0;
//}
//P1024
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cstdio> // 1. 包含 printf
//#include <cmath>  // 2. 包含 abs(double)
//using namespace std;
//double a, b, c, d;
//double f(double x)
//{   
//    return a * x * x * x + b * x * x + c * x + d;
//}
//double find(double l, double r)
//{
//    if (abs(l - r) < 0.001)return l;
//    double mid = (l + r) / 2;
//    if (f(l) * f(mid) < 0)r = mid;
//    else l = mid;
//    return find(l, r);
//}
//int main() 
// {
//    cin >> a >> b >> c >> d;
//    for (int i = -100; i <= 100; i++)
//    {
//        double y1 = f(i), y2 = f(i + 1);
//        if (!y1)printf("%.2f ", (double)i);/****///这一句是重中之重，一开始我把i写成了y1，而且这里i不强制转换会输出0；
//        if (y1 * y2 < 0)printf("%.2f ", find(i, i + 1));//少了个空格
//    }
//
//    return 0;
//}