#include<vector>

class Solution {
public:
    void dfs(vector<int>& candidates, int cur_vis_index, int target) {
        if (0 == target) {
            res.push_back(tmp);
            return;
        }

        if (target < 0 || cur_vis_index == candidates.size()) {
            return;
        }

        dfs(candidates, cur_vis_index+1, target);

        // 可以重复选择的话：选到了第1个数，再选一下第一个数，那么cur_vis_index是不动的
        // 但是target是需要减去当前这个数的值的
        // 然后再将当前这个数push进去tmp数组
        // 递归调用dfs，返回后，pop出去，表示该分支结束
        tmp.push_back(candidates[cur_vis_index]);
        dfs(candidates, cur_vis_index, target-candidates[cur_vis_index]);
        tmp.pop_back();

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> tmp;
};