#include<iostream>
#include<vector>
using namespace std;

/*
dp[i][j]：粉刷前i个墙，并且第i个强粉刷成第j个颜色的最小花费成本
边界条件：粉刷第1个墙 d[0][j] = costs[0][j]
状态转移方程：粉刷第 i(i>=2)个墙的最小花费成本
    就是上一个dp的第j的最小花费+当前的花费
    如果dp[i+1][0] = min(dp[i][1],dp[i][2]) + costs[i+1][0]
    如果dp[i+1][1] = min(dp[i][0],dp[i][2]) + costs[i+1][1]
    如果dp[i+1][2] = min(dp[i][0],dp[i][0]) + costs[i+1][2]
*/
class Solution_dp {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> dp(3);
        int n = costs.size();
        
        for(int i = 0; i < 3; ++i){
            dp[i] = costs[0][i];
        }

        for(int i = 1; i < n; ++i){
            vector<int> dpTmp(3);
            for(int j = 0; j < 3; ++j){
                dpTmp[j] = min(dp[(j+1)%3],dp[(j+2)%3]) + costs[i][j];
            }
            dp = dpTmp;
        }

        return min(dp[0], min(dp[1],dp[2]));
    }
};

// 暴力dfs，遍历所有可能性
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        nMinCost = 20001;
        // dfs(costs, 0, 0, 0);
        for(int i = 0; i < 3; ++i) {
            dfs(costs, costs[0][i], i, 1);
        }
        return nMinCost;
    }
private:
    void dfs(vector<vector<int>> &costs, int nCurrCost ,int index, int indexHouse)
    {
        if(indexHouse == costs.size()){
            nMinCost = nCurrCost > nMinCost ? nMinCost : nCurrCost;
            return;
        }
        for(int i = 0; i < 3; ++i) {
            if(index == i) {
                continue;
            }
            dfs(costs, nCurrCost+costs[indexHouse][i], i, indexHouse+1);
        }
    }
private:
    int nMinCost;
};

int main()
{
    vector<vector<int>> costs{{3,5,3},{6,17,6},{7,13,18},{9,10,18}};
    Solution a;
    cout << a.minCost(costs) << endl;
    return 0;
}