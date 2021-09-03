/*
层次遍历
*/

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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return level(root);
    }
private:
    int level(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int depth = 0;
        while (!q.empty()) {
            for (int i = q.size() - 1; i >= 0; --i) {
                TreeNode* now = q.front();
                q.pop();
                if (now->left != NULL) {
                    q.push(now->left);
                }
                if (now->right != NULL) {
                    q.push(now->right);
                }
            }

            depth++;
        }

        return depth;
    }
};


/*
先序遍历
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return max(maxDepth(root->left),maxDepth(root->right)) + 1;
    }
};