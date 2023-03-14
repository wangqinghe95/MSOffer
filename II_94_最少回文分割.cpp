/**
 * @file II_94_最少回文分割.cpp
 * @author your name (you@domain.com)
 * @brief 
 *  问题：将一个字符串分成全是回文串的子串，一个字符是自己的回文子串
 *  思路：找出整个字符串的回文串，然后根据选定的回文串去确定回文串的切割
 * @version 0.1
 * @date 2023-03-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> isPalindrome(s.size(), vector<bool>(s.size(), false));

        int cenL = 0;
        int cenR = 0;
        while(cenR < s.size()) {
            int left = cenL;
            int right = cenR;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                isPalindrome[left--][right++] = true;
            }

            cenR > cenL ? cenL++ : cenR++;
            
        }

        vector<int> dp(s.size(), 0);
        for(int i = 0; i < s.size(); ++i) {
            if(isPalindrome[0][i] == true) {
                dp[i] = 0;
            }
            else{
                dp[i] = i;
                for(int j = 1;  j <= i; ++j) {
                    if(true ==  isPalindrome[j][i]){
                        dp[i] = min(dp[i], dp[j-1]+1);
                    }
                }
            }
        }
        return dp.back();
    }

};

int main()
{
    string s = "ab";
    Solution a;
    cout << a.minCut(s) << endl;
    return 0;
}