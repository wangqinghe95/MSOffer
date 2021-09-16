#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int hash[15] = {0};
        int begin_index = 14;
        int end_index = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash[nums[i]] == 0) {
                hash[nums[i]]++;
            }
            else if (nums[i] == 0) {    // 非0数重合必为false
                hash[nums[i]]++;
            }
            else {
                return false;
            }
            if (nums[i] < begin_index && nums[i] != 0) {
                begin_index = nums[i];
            }
            if (end_index < nums[i]) {
                end_index = nums[i];
            }
        }

        if (end_index-begin_index+hash[0] <= 6 && end_index-begin_index <= 4) {
            return true;
        }
        else {
            return false;
        }
    }
};
int main() {
    vector<int> nums{0,0,8,4,5};
    Solution a;
    cout << a.isStraight(nums);
    return 0;
}