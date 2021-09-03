/*
先序遍历+深度：大量计算，时间复杂度太高
    unordered_map：保存已经计算过的结点高度（时间复杂度还是挺高的）
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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        return (abs(getHeight(root->left)-getHeight(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right);
        
    }
private:
    int getHeight(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }

        if (nodeHeight.find(node) == nodeHeight.end()) {
            nodeHeight[node] = max(getHeight(node->left),getHeight(node->right)) + 1;
        }

        return nodeHeight[node];
    }
    unordered_map<TreeNode*, int> nodeHeight;
};


/*
后续遍历+减支
*/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return recu(root) != -1;
    }
private:
    int recu(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }

        int left = recu(node->left);
        if (left == -1) {
            return -1;
        }

        int right = recu(node->right);
        if (right == -1) {
            return -1;
        }

        return abs(left-right) < 2 ? max(left,right) + 1 : -1;
    }
};