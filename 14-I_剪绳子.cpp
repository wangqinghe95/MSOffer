/*
直接上数学结论：1、当所有绳段长度相等时，乘积最大
2、最优的绳段长度为 3.
其中，最优绳段长度为 3 的意思是，当一段绳子按照 3 的单位长度相乘时，其组合乘积是最大的
*/

class Solution {
public:
    int cuttingRope(int n) {
        if (n < 3){
            return 1;
        }
        if (n == 3){
            return 2;
        }
        if (n == 4){
            return 4;
        }

        int ans = 1;
        int cnt = 1;
        while (n > 4)
        {
            cnt *= 3;
            n -= 3;
        }

        ans = cnt * n;
        return ans;        
    }
};

 
/*
动态规划思路：

*/
class Solution {
public:
    int cuttingRope(int n) {
        int* dp = new int[n+1];
        dp[0] = 0; 
        dp[1] = 1;

        auto Max = [](int a, int b)->int{
            return a > b ? a : b;
        };

        for (int i = 2; i <= n; ++i){
            for (int j = 1; j <= i/2; ++j){
                dp[i] = Max(dp[i], Max(j*(i-j), j *dp[i-j]));
            }
        }
        return dp[n];
    }
};

