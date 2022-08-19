

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backTrace(res, nums, 0, nums.size());
        return res;
    }
private:
    void backTrace(vector<vector<int>> &res, vector<int>&nums, int first, int len){
        if (first == len) {
            res.push_back(nums);
            return;
        }

        for (int i = first; i < len; ++i) {
            swap(nums[i], nums[first]);
            backTrace(res, nums, first+1, len);
            swap(nums[i],nums[first]);
        }
    }
};