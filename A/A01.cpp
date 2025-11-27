//using namespace std;
//#include<iostream>
//#include<algorithm>
// int main()
//{
//	 string a, b;
//	 cin >> a;
//	 cin >> b;
//	 reverse(a.begin(),a.end());
//	 reverse(b.begin(),b.end());
//	 if (a.size() > b.size())
//	 {
//		 b.append(a.size() - b.size(), '0');
//	 }
//	 else
//	 {
//		 a.append(b.size() - a.size(), '0');
//	 }
//	 int i=0;
//	 string s;
//	 int x,flow=0;
//	 for (; i < a.size();i++)
//	 {
//		 x = (a[i] - '0') + (b[i] - '0')+flow;
//		 if (x >= 10)
//		 {
//			 flow = 1;
//		 }
//		 else
//		 {
//			 flow = 0;
//		 }
//		 x %= 10;
//		 s = s + char('0' + x);
//	 }
//	 if (flow == 1)
//		 s = s + '1';
//	 reverse(s.begin(), s.end());
//	 cout << s;
//	return 0;
//}