/*
在这道题的解析中动态规划的初始状态是 dp[0] = 1, dp[1] = 1
我不明白的是为什么不是 dp[1] = 1, dp[2] = 1;
然后看了一个说法：dp[i]表示到第 i 个台阶的方法
i = 2 时，是有两种跳法的，一个是直接调两步，一个是一步一步跳两次
*/


// 递归
class Solution {
public:
    int getWays(int n, vector<int>& res){
        if (n <= 1){
            return 1;
        }
        if (res[n] == -1){
            res[n] = (getWays(n-1,res)+getWays(n-2,res))%1000000007;
        }

        return res[n];
    }
    int numWays(int n) {
        vector<int> res(n+1, -1);
        return getWays(n, res);
    }
};

//迭代-dp
class Solution {
public:
    int numWays(int n) {
        if (n <= 1){
            return 1;
        }
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++){
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
        }

        return dp[n];
    }
};