/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);

        vector<int> res;

        while(!q.empty()) {
            TreeNode* now = q.front();
            q.pop();
            res.push_back(now->val);
            if (now->left != NULL) {
                q.push(now->left);
            }
            if (now->right != NULL) {
                q.push(now->right);
            }  
        }

        return res;
    }
};