#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    void dfs(vector<int>& nums, int cur) {
        if(cur == nums.size()) {
            res.push_back(tmp);
            return;
        }

        tmp.push_back(nums[cur]);
        dfs(nums, cur+1);
        tmp.pop_back();
        dfs(nums,cur+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
private:
    vector<int> tmp;
public:
    vector<vector<int>> res;
};

int main()
{
    Solution a;
    vector<int> nums{1,2,3};
    a.subsets(nums);
    return 0;
}