//这一章是滑动窗口，自己前面完全没有学过，连科普都没有过，所以做起来会比较困难，所以说没关系
//我们今明两天把这个东西完全整明白
//下面是不定长滑动窗口
//https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/

//#include <iostream>
//#include <string>
//#include <vector>
//#include<set>
//#include <unordered_map>
//using namespace std;
//int lengthOfLongestSubstring(string s) {
//    int ans = 0;
//    unordered_map<char, int> charCnt;
//    for (int left = 0, right = 0; right < s.size(); right++) {
//        // 第一次进入for循环是空子串，不满足状态
//        // right加入窗口
//        charCnt[s[right]]++;
//        while (charCnt[s[right]] > 1) {
//            // 根据情况收集答案
//            // left移出窗口
//            charCnt[s[left]]--;
//            left++;
//        }
//        // 不满足状态（根据情况收集答案）
//        ans = max(ans, right - left + 1);
//    }
//    return ans;
//}
//int main()
//{
//    string s;
//    cin >> s;
//    cout << lengthOfLongestSubstring(s);
//    return 0;
//}
//https://leetcode.cn/problems/minimum-size-subarray-sum/
//leetcode209
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <limits> // 用于获取最大整数值
//
//using namespace std;
//int minSubArrayLen(int target, vector<int>& nums) 
//{
//    int n = nums.size();
//    if (n == 0) return 0;
//    int min_len = numeric_limits<int>::max();
//    int l = 0; // 窗口左边界
//    int current_sum = 0; // 当前窗口 [l, r] 的总和
//
//    // 外层循环：右指针 r 负责扩张窗口，直到遍历完整个数组
//    for (int r = 0; r < n; ++r) 
//    {
//        // 1. 扩张窗口：将 nums[r] 加入当前和
//        current_sum += nums[r];
//
//        // 2. 内层循环：收缩窗口，直到条件不再满足
//        // 当 current_sum >= target 时，说明找到了一个有效子数组
//        while (current_sum >= target) 
//        {
//            // 找到了一个有效子数组 [l, r]，更新最小长度
//            min_len = min(min_len, r - l + 1);
//
//            // 尝试收缩窗口：将 nums[l] 移出窗口
//            current_sum -= nums[l];
//            l++; // 左边界右移
//        }
//    }
//    return (min_len == numeric_limits<int>::max()) ? 0 : min_len;
//}
//
//int main() 
//{
//
//    int n;
//    if (!(cin >> n)) return 0;
//    vector<int> nums(n);
//    for (int i = 0; i < n; i++) 
//    {
//        cin >> nums[i];
//    }
//    int target;
//    cin >> target;
//    cout << minSubArrayLen(target, nums) << "\n";
//    return 0;
//}
//
//https://leetcode.cn/problems/subarray-product-less-than-k/description/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <limits> // 用于获取最大整数值
//
//using namespace std;
//int numSubarrayProductLessThanK(vector<int>nums,int k) 
//{
//    int mul = 1;
//    int ans = 0;
//    for (int left = 0, right = 0; right < nums.size(); right++)
//    {
//        mul *= nums[right];
//        //为什么要加上left<=right//保证数组元素过大超出k的情况，可能是会出现的
//        while (mul >= k && left <= right)
//        {
//            mul /= nums[left];
//            left++;
//        }
//        //为什么是这么样加的
//        //因为加入一个新元素之后，它是在原来的那些子数组上都可以加一个nums[r],所以直接加就可以了
//        if (right >= left)
//        {
//            ans += right - left + 1;
//        }
//        
//    }
//    return ans;
//}
//
//int main() 
//{
//
//    int n;
//    if (!(cin >> n)) return 0;
//    vector<int> nums(n);
//    for (int i = 0; i < n; i++) 
//    {
//        cin >> nums[i];
//    }
//    int k;
//    cin >> k;
//    cout << numSubarrayProductLessThanK(nums,k) << "\n";
//    return 0;
//}
//
//滑动窗口的细节也是非常多的
//https://www.luogu.com.cn/problem/P1886
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//const int N = 1000010;
//int n, k, a[N], q[N];
//
//int main()
//{
//    //输入
//    cin >> n >> k;
//    for (int i = 1; i <= n; i++)cin >> a[i];
//    //滑动窗口，最小值输出
//    for (int i = 1, h = 1, t = 0; i <= n; i++)
//    {
//        while (h <= t && q[h] < i - k + 1)h++;////队头出队(队列不空且队头元素滑出窗口) ,这里用if也行，因为只会出一次队
//        while (h <= t && a[q[t]] >= a[i])t--;//队尾出队(队列不空且新元素更优)
//        q[++t] = i;//队尾入队(存储下标 方便判断队头出队)
//        if (i >= k) printf("%d ", a[q[h]]);   //输出最小值
//    }
//    cout << endl;
//    for (int i = 1, h = 1, t = 0; i <= n; i++)
//    {
//        while (h <= t && q[h] < i - k + 1)h++;
//        while (h <= t && a[q[t]] <= a[i])t--;
//        q[++t] = i;
//        if(i>=k) printf("%d ", a[q[h]]);
//    }
//    return 0;
//}
//https://leetcode.cn/problems/find-all-anagrams-in-a-string/
//#include <iostream>
//#include <string>
//#include <vector>
//#include<unordered_map>
//using namespace std;
//
//vector<int> findAnagrams(string s, string p)
//{
//    vector<int> ans;
//    unordered_map<char, int> cntChar;
//    for (char c : p)
//    {
//        cntChar[c]++;//统计字符个数
//    }
//    //滑动窗口
//    for (int  l = 0, r = 0; r < s.size(); r++)
//    {
//        //加入窗口
//        cntChar[s[r]]--;
//        //这个字符是不存在字符
//        while (cntChar[s[r]] < 0)
//        {
//            //左窗口滑动
//            cntChar[s[l++]]++;   
//        }
//        if (r - l + 1 == p.size())ans.push_back(l);
//    }
//    return ans;
//}
//
//int main()
//{
//    string s, p;
//    cin >> s >> p;
//    return 0;
//}
//可变长滑动窗口掌握的还可以了

//https://leetcode.cn/problems/minimum-window-substring/
//两个一样长的还不行
//#include <iostream>
//#include <string>
//#include <vector>
//#include<unordered_map>
//using namespace std;
//string minWindow(string s, string t)
//{
//    int count=0;//用于统计t串有多少种字符，如果该字符没有了，那么count--，加回来了count++；
//    int length = s.size()+1;//用于统计最短串长度
//    int ptr = -1;//字串下标,等于-1时没有最优解
//    unordered_map<char, int> cntChar;
//    for (char c : t)
//    {
//        cntChar[c]++;
//        if (cntChar[c] == 1)count++;
//    }
//    for (int l = 0, r = 0; r < s.size(); r++)
//    {
//        //加入窗口
//        cntChar[s[r]]--;
//        if (cntChar[s[r]] == 0)count--;
//        //这个字符是不存在字符
//        while (cntChar[s[l]] < 0)
//        {
//            //左窗口滑动
//            cntChar[s[l++]]++;   
//        }
//        //找到了
//        if (count == 0)
//        {   
//            //找到更小串
//            if (length > r - l + 1)
//            {
//                length = r - l + 1;
//                ptr = l;
//            }
//            //这个时候我们可以动左指针了
//            //这里忘了更新字符个数和cnt
//            cntChar[s[l++]]++;
//            if (cntChar[s[l-1]]> 0)count++;
//
//        }
//    }
//    if (ptr == -1)return "";
//    else return s.substr(ptr, length);
//}
//int main()
//{
//    string s, t;
//    cin >> s >> t;
//    cout << minWindow(s, t);
//    return 0;
//}
//nice
//https://www.luogu.com.cn/problem/P2216
//这个有点难写啊，每个拆分出来都没那么难，但是合起来有点难
