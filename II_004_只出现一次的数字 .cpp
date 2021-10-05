#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[32] = {0};
        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                count[i] += (num >> (31-i)) & 1;
            }
        }

        int res = 0;
        for (int i = 0; i < 32; ++i) {
            res = (res << 1) + count[i] % 3;
        }
        return res;
    }
};

int main() {
    Solution a;
    vector<int> nums{2,2,3,2,5,5};
    cout << a.singleNumber(nums);
    return 0;
}