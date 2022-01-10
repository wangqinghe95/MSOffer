/*
后序遍历判断该点是否要被删除
当该节点值位0，且无左右孩子时
直接返回nullptr作为父节点的子树
*/

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
    TreeNode* pruneTree(TreeNode* root) {
        return inOrder(root);
        
    }
private:
    TreeNode* inOrder(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        root->left = inOrder(root->left);
        root->right = inOrder(root->right);
        if (root->left == nullptr && root->right == nullptr && root->val == 0) {
            return nullptr;
        }
        return root;
    }
};