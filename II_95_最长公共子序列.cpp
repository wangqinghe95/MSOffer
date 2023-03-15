#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1));

        auto max = [](int a, int b) {
            return a > b ? a : b;
        };

        for(int i = 1; i <= n; ++i){
            char c1 = text1.at(i-1);
            for(int j = 1; j <= m; ++j) {
                char c2 = text2.at(j-1);
                if(c1 == c2) {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};

int main()
{
    string text1 = "abcde";
    string text2 = "ace";
    Solution a;
    cout << a.longestCommonSubsequence(text1,text2) << endl;
    return 0;
}