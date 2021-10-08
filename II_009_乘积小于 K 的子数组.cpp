

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        long sum = 1;
        int count = 0;
        for (; right < nums.size(); ++right) {
            sum *= nums[right];
            while (sum >= k && left <= right) {
                sum /= nums[left++];
            }
            count += right - left + 1;
        }
        return count;
    }
};