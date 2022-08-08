
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        if(target < candidates[0]) {
            return res;
        }

        dfs(candidates, 0, target);
        return res;
    }
private:
    void dfs(vector<int>& candidates, int cur_index ,int cur_target) {
        if (cur_target == 0) {
            res.push_back(tmp);
            return;
        }

        if (cur_index == candidates.size() || cur_index < 0) {
            return;
        }

        for (int i = cur_index; i < candidates.size(); ++i) {
            if(i > cur_index && candidates[i] == candidates[i-1]) {
                continue;
            }

            if (cur_target < candidates[i]) {
                break;
            }

            tmp.push_back(candidates[i]);
            dfs(candidates, i+1, cur_target-candidates[i]);
            tmp.pop_back();
        }
    }
private:
    vector<vector<int>> res;
    vector<int> tmp;
};