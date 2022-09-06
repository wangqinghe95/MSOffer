

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int nBehindOneCost = 0; // 表示f[n-1]
        int nBehindTwoCost = 0; // 表示 f[n-2]
        int nCurCost = 0;       // 表示 f[n]
        for(int i = 2; i <= cost.size(); ++i) {
            nCurCost = min(nBehindOneCost+cost[i-1], nBehindTwoCost+cost[i-2]); // 求出 f[n]
            nBehindTwoCost = nBehindOneCost;        // 接下来求第 N+1 项，所有的值都往前+1， 第n-1项值给n-2
            nBehindOneCost = nCurCost;              // 第n项值给 n-1
        }

        return nCurCost;
    }
};