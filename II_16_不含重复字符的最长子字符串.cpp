#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[130] = {0};
        int left = 0;
        int max = 0;    // 初始化为 0 ，是为了处理字符串判断情况
        for (int right = 0; right < s.length(); ++right) {
            hash[s[right]]++;
            while (hash[s[right]] > 1) {
                hash[s[left]]--;
                left++;
            }
            int len = right - left + 1;
            max = max > len ? max : len;
        }

        return max;
    }
};

int main() {
    string s("bbbbb");
    Solution a;
    cout << a.lengthOfLongestSubstring(s) << endl;
    return 0;
}