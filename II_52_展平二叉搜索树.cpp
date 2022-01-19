#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 *  使用中序遍历来改变节点的左右树
 * 制造一个头节点，按照中序遍历的访问顺序
 * 在将当前的节点赋值给上一个节点的右孩子，再将本节点的左孩子置空
 * 再将当前节点赋值给 resNode，记录为上一个节点
 * 最后返回的时候，返回头结点的右孩子
 *
*/
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        resNode = new TreeNode(-1);
        TreeNode* dummyNode = resNode;
        inOrder(root);
        return dummyNode->right;
    }
public:
    TreeNode* resNode;
private:
    void inOrder(TreeNode* root) {
        if (!root) {
            return ;
        }

        inOrder(root->left);

        resNode->right = root;
        root->left = nullptr;
        resNode = root; 

        inOrder(root->right);
    }
};

int main() {

}