#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum = 0;
        int cnt = 0;
        mp[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += (nums[i] == 0) ? -1 : 1;
            if (mp.count(sum)) {
                cnt = max(cnt, i - mp[sum]);
            }
            else {
                mp[sum] = i;
            }
        }

        return cnt;
    }
};

int main() {
    Solution a;
    vector<int> nums{0, 1, 0, 0, 1};
    cout << a.findMaxLength(nums) << endl;
    return 0;
}