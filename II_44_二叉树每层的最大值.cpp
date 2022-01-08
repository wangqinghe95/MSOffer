/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {
            return vector<int> {};
        }
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        // res.push_back(root->val);
        auto max = [](int x, int y) {
            return x > y ? x : y;
        };
        while (!q.empty()) {
            int maxLevelNum = INT_MIN;  // note negative
            for (int i = q.size()-1; i >= 0; --i) {
                TreeNode* cur = q.front();
                q.pop();
                maxLevelNum = max(maxLevelNum, cur->val);

                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            res.push_back(maxLevelNum);

        }

        return res;
    }
};