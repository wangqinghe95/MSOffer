/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
二叉树的公共祖先：找两个节点的公共祖先，从根节点递归遍历整个树节点
    根据父节点的情况，当前被访问的节点和要寻找的两个节点只有二种情况：
    1、p，q两个节点在 root 节点两侧，（不可能是同一侧，如果是同一侧就说明该节点不是最近的父节点）
    2、当前节点为 q，或q，另一个节点在它的子树中

    遍历方式使用先序遍历，如果左子树中没有返回右子树（可能有值，可能为空），如果右子树没有返回左子树
    如果左右子树都有值，返回该节点（此时该节点为最近公共祖先）

如果
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == root || q == root) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
        }

        return root;
    }
};