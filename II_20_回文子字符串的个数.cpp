#include<string>
#include<iostream>
#include<vector>
using namespace std;

// n = 3
// i < 5
// i = 0,l = 0, r = 0
// i = 1, l = 0, r = 1
// i = 2, l = 1, r = 1; l = 0, r = 2
// i = 3, l = 1, r = 2; l = 0, r = 3
/*
暴力破解：从头开始遍历看看每一个字串是不是回文串
方法：根据回文串的特点，从头找到回文中心，再根据这个回文中心向两边延展，在有效的字符串中看看是不是回文串
回文中心：一个字符串 s = asfhwad ，长度为 7，那么那他的回文中心就是 0，0.5，1，1.5 ... 6.5（为啥要到字符串结尾呢）
然后扩充一下，都乘以 2，就是 2*n-1，也就是说，遍历到 2n-1，然后找回文中心点，向两边拓展即可

算法的时间复杂度是 O(n^2)
*/
class Solution_1 {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < 2 * n - 1; ++i) {
            int l = i / 2;
            int r = i / 2 + i % 2;
            while(l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++ans;
            }
        }

        return ans;
    }
};


// Manacher 算法--没看懂
// s = abc
// t = #a#b#c#! size = 7 n = 6
// i = 1, f[1] = 1
// t[1+1] == t[1-1]? => t[2] == t[0]?   f[1] = 2
// t[1+2] == t[1-2]? => t[3] = t[-1]
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        string t = "$#";
        for (const char &c: s) {
            t += c;
            t += '#';
        }
        n = t.size();
        t += '!';

        auto f = vector <int> (n);
        int iMax = 0, rMax = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            // 初始化 f[i]
            f[i] = (i <= rMax) ? min(rMax - i + 1, f[2 * iMax - i]) : 1;
            // 中心拓展
            while (t[i + f[i]] == t[i - f[i]]) ++f[i];
            // 动态维护 iMax 和 rMax
            if (i + f[i] - 1 > rMax) {
                iMax = i;
                rMax = i + f[i] - 1;
            }
            // 统计答案, 当前贡献为 (f[i] - 1) / 2 上取整
            ans += (f[i] / 2);
        }

        return ans;
    }
};

int main() {
    string s("abc");
    Solution a;
    cout << a.countSubstrings(s) << endl;
    return 0;
}