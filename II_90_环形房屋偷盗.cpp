/*
思路：环形房间，就是怎么处理最后一个值和第一个值的相邻问题
也就是说，当dp到最后一个数组的时候，到底取不取这个数
解决方案就是隔开：
对 (0, nums.size()-2) 和 (1, nums.size()-1) 这两个范围找最大的
这样就可以不管收尾是否相连了
*/

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int robByRange(vector<int>& nums, int start, int end){
        vector<int> dp(nums.size()+1, 0);
        dp[start] = nums[start];
        dp[start+1] = max(nums[start],nums[start+1]);
        for(int i = start+2; i <= end; ++i){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }

        return max(robByRange(nums,0,nums.size()-2), robByRange(nums,1, nums.size()-1));
    }
};

int main()
{
    Solution a;
    vector<int> nums{1,7,9,2};
    cout << a.rob(nums) << endl;
    return 0;
}