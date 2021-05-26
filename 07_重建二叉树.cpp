/*
先序中序建树
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
    TreeNode* create(vector<int>& pre, int preL, int preR
                    , vector<int>& in, int inL, int inR)
    {
        if(preL > preR){
            return NULL;
        }

        TreeNode* root = new TreeNode;
        root->val = pre[preL];

        int k = inL;
        for(; k <= inR; k++){
            if(in[k] == pre[preL]){
                break;
            }
        }

        int numLeft = k - inL;
        root->left = create(pre, preL+1, preL+numLeft, in, inL, k-1);
        root->right = create(pre, preL+numLeft+1, preR, in, k+1, inR);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return create(preorder, 0, preorder.size()-1
                        , inorder, 0, inorder.size()-1);
    }
};