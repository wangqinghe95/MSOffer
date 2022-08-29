#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        hash.assign(n, vector<int>(n));

        dfs(s, 0);
        return res;
    }
private:
    void dfs(string& s, int index) {
        if (index == n) {
            res.push_back(ans);
            return;
        }

        for(int i = index; i < n; ++i) {
            if(isPalindrome(s,index,i) == 1) {
                ans.push_back(s.substr(index,i-index+1));
                dfs(s, i+1);
                ans.pop_back();
            }
        }
    }
    int isPalindrome(string& s, int i, int j) {
        if(hash[i][j]){
            return hash[i][j];
        }

        if (i >= j) {   // 必须是 i >= j，什么时候会有大于的情况呢
            return hash[i][j] = 1;
        }

        return (hash[i][j] = (s[i] == s[j] ? isPalindrome(s,i+1,j-1) : -1));
    }
private:
    vector<vector<string>> res;
    vector<vector<int>> hash;
    vector<string> ans;
    int n;
};

class Solution_1 {
public:
    vector<vector<string>> partition(string s) {
        n = s.size();

        hash.assign(n, vector<int>(n, 1));
        for (int i = n-1; i >= 0; --i) {
            for (int j = i+1; j < n; ++j) {
                hash[i][j] = (s[i] == s[j] && hash[i+1][j-1]);
            }
        }
        dfs(s, 0);
        return res;
    }
private:
    void dfs(string& s, int index) {
        if (index == n) {
            res.push_back(ans);
            return;
        }

        for (int i = index; i < n; ++i) {
            if(hash[index][i]) {
                ans.push_back(s.substr(i, i-index+1));
                dfs(s, i+1);
                ans.pop_back();
            }
        }
    }
private:
    vector<vector<int>> hash;
    vector<vector<string>> res;
    vector<string> ans;
    int n;
};

int main()
{
    Solution a;

    return 0;
}