#include<iostream>
#include<string>
using namespace std;


/*
无脑遍历字符串
*/
class Solution {
public:
    int getSubMaxLen(string& s, int &start) {
        int hash[130] = {0};
        int len = 0;
        int i = start;
        for (; i < s.size(); ++i) {
            if (hash[s[i]] == 0){
                hash[s[i]] = i+1;
                len++;
            }
            else {
                break;
            }
        }
        start = i == s.size() ? i : hash[s[i]];
        return len;
    }
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int max_sub_len = 0;
        while (start < s.size()) {
            int len = getSubMaxLen(s, start) ;
            max_sub_len = len > max_sub_len ? len : max_sub_len;
        }
        return max_sub_len;
    }
};
int main() {
    Solution a;
    string s("dvdf");
    cout << a.lengthOfLongestSubstring(s) << endl;
    return 0;
}