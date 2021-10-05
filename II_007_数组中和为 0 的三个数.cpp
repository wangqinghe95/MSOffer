#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;


// 去重
class Solution_2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j-1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k+1]) {
                        k--;
                    }
                }
                else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                }
                else {
                    j++;
                }
            }
        }
        return res;
    }
};

// 未去重
class Solution_1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {{}};
        }

        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int k = nums.size() - 1; k > j; k--) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        res.push_back({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums{-2,0,3,-1,4,0,3,4,1,1,1,-3,-5,4,0};
    Solution_2 b;
    b.threeSum(nums);
    return 0;
}