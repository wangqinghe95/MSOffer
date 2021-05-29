/*
由于有大数，动态规划期间无法取模，取模后影响下一个dp值
所以这题只能使用贪心
*/

class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4) {
            return n-1;
        }

        if (4 == n){
            return 4;
        }

        long ans = 1;
        while ( n > 4){
            ans = (ans * 3) % 1000000007;
            n -= 3;
        }
        ans = (ans * n) % 1000000007;
        return ans;
    }
};