#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
mp  0   1
    1   1
    3   1

1,2,3   3
1   sum-k = -2
3   sum-k = 0   1
6   sum-k = 3   2 
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count = 0;
        int sum = 0;
        mp[0] = 1;
        for (int num : nums) {
            sum += num;
            count += (mp.count(sum-k)) ? mp[sum-k] : 0;
            mp.count(sum) ? mp[sum]++ : mp[sum] = 1;
        }
        return count;
    }
};

/*
滑动窗口的数组中不能含有负数
*/
class Solution_1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int count = 0;

        while (right < nums.size()) {
            sum += nums[right++];
            while (sum > k && left < right) {
                sum -= nums[left++]; 
            }
            if (sum == k) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums{-2,1,2,3};
    int target = 3;
    Solution a;
    cout << a.subarraySum(nums, target) << endl;
    return 0;
}