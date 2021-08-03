#include"createTree.hpp"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            res.push_back(vector<int> ());
            for (int i = q.size(); i > 0; --i) {
                TreeNode* now = q.front();
                q.pop();

                // 用 res.back() 替换 es[res.size()-1] 瞬间运行速度就打败了100%
                // res[res.size()-1].push_back(now->val);
                res.back().push_back(now->val); 
                if (now->left != NULL) {
                    q.push(now->left);
                }

                if(now->right != NULL) {
                    q.push(now->right);
                }
            }

            if (!(res.size() & 1)) {
                reverse(res.back().begin(), res.back().end());
            }
        }

        return res;
    }
};