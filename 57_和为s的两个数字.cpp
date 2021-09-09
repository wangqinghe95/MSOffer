/*
双指针
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left != right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                break;
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return vector<int>{nums[left],nums[right]};
    }
};
int main() {
    Solution a;
    vector<int> nums{10,26,30,31,47,60};
    vector<int> res = a.twoSum(nums, 40);
    return 0;
}