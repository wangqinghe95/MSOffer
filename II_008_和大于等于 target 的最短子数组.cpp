/*
双指针：前指针一直向后移。移动过程中累加移动的和。如果该和得值大于等于target
    就将left指针往后移动，并从sum中减去left指向的值。直到left指针大于right 指针或者sum值小于target
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0, count = INT_MAX;
        for (; right < nums.size(); ++right) {
            sum += nums[right];
            while (left <= right && sum >= target) {
                count = min(count, right-left+1);
                sum -= nums[left++];
            }
        }

        return count == INT_MAX ? 0 : count;
    }
};