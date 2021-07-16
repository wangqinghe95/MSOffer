/* 
 * 先序遍历，然后交换每个节点
 */

class Solution {
public:
    void exchange(TreeNode* &left, TreeNode* &right) {
        TreeNode* tmp = left;
        left = right;
        right = tmp;
    }
    TreeNode* mirrorTree(TreeNode* root) {
        if (root != NULL) {
            exchange(root->left, root->right);
            root->left = mirrorTree(root->left);
            root->right = mirrorTree(root->right);
        }
        
        return root;
    }
};