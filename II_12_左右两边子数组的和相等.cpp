#include<iostream>
#include<vector>
using namespace std;

/*
时间复杂度O(n)
空间复杂度O(1)
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < nums.size(); ++i) {
            total += nums[i];
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (total - sum - nums[i] == sum) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};


/*
时间复杂度O(n)
空间复杂度O(n)
*/
class Solution_1 {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n+1, 0);
        for (int i = n - 1; i >= 0 ; --i) {
            right[i] = right[i+1] + nums[i];
        }

        int left_sum = 0;
        for (int i = 0; i < n; ++i) {
            if (left_sum == right[i+1]) {
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};

int main() {
    vector<int> nums{1,7,3,6,5,6};
    Solution a;
    cout << a.pivotIndex(nums) << endl;
    return 0;
}