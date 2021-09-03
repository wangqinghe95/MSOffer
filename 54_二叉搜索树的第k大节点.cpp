
/*
中序遍历：将二叉树的值按顺序保存到一个数组中
*/

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector<int> res;
        preOrder(root, res);

        return res[res.size() - k];
    }
private:
    void preOrder(TreeNode* root, vector<int>& res) {
        if (root != NULL) {
            preOrder(root->left, res);
            res.push_back(root->val);
            preOrder(root->right, res);
        }
    }
};

/*
中序遍历：右根左顺序
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
    int res;
    int kthLargest(TreeNode* root, int k) {
        order(root, k);
        return res;
    }
private:
    void order(TreeNode* root, int& k) {
        if (root == NULL || k <= 0) {
            return;
        }

        order(root->right, k);
        k--;
        if (k == 0) {
            res = root->val;
            return;
        }
        order(root->left, k);
    }
};