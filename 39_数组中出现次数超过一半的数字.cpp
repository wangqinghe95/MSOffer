#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int majorityNum = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (count == 0) {
                majorityNum = nums[i];
                count = 1;
                continue;
            }
            if (nums[i] == majorityNum) {
                count++;
            }
            else {
                count--;
            }
        }

        return majorityNum;
    }
};

int main() {
    Solution a;
    vector<int> nums{3,2,3};
    a.majorityElement(nums);
}

