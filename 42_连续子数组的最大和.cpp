/*
动态规划：

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int max = dp[0];
        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] + dp[i-1] > nums[i]) {
                dp[i] = dp[i-1] + nums[i];
            }
            else {
                dp[i] = nums[i];
            }
            max = dp[i] > max ? dp[i] : max;
        }

        return max;
    }
};