class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        upperLimit = n;
        sizeLimit = k;
        dfs(1);
        return res;
    }
private:
    void dfs(int cur) {

        if (tmp.size() == sizeLimit) {
            res.push_back(tmp);
            return;
        }

        // 当前已经进入保持的数字数量 + 剩下还没有遍历的数字 < 需要的数字数量
        if (tmp.size() + (upperLimit - cur + 1) < sizeLimit) {
        // if (cur == upperLimit + 1) {
            return;
        }

        tmp.push_back(cur);
        dfs(cur+1);
        tmp.pop_back();
        dfs(cur+1);
    }
private:
    vector<int> tmp;
    vector<vector<int>> res;
    int upperLimit;
    int sizeLimit;
};