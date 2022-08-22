/*
生成有效的括号匹配：
    和一般的全排列相比的区别是，在 dfs 时，左括号的数量要大于等于右括号的数量
    且当左括号数=右括号数=n时，符合要求。

思路：
    在dfs过程中，把控一下左括号数＜有括号数时，不合法返回
    左括号时＜n 时，添加一个左括号和不添加两个分支
    右括号＜左括号数时，两个分支（添加一个右括号和不添加右括号）
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string strParenthesis;
        dfs(res, strParenthesis, 0, 0, n);
        return res;
    }
private:
    void dfs(vector<string>& res, string &strParenthesis ,int nLeftIndex, int nRightIndex, int n)
    {
        if(strParenthesis.size() == n*2) {
            res.push_back(strParenthesis);
            return;
        }
        if(nLeftIndex < nRightIndex){
            return;
        }
        if(nLeftIndex < n) {
            strParenthesis.push_back('(');
            dfs(res,strParenthesis,nLeftIndex+1,nRightIndex,n);
            strParenthesis.pop_back();
        }

        if(nRightIndex < nLeftIndex) {
            strParenthesis.push_back(')');
            dfs(res, strParenthesis, nLeftIndex, nRightIndex+1, n);
            strParenthesis.pop_back();
        }

    }
};