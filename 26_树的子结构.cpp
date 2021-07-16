/*
判断树A中是否包含树B步骤：
1、先序遍历树A的每个节点，找到找到和树B根节点对应的节点
2、再根据树A的该节点，再找树A的左右子节点是否能与树B的左右子节点对应
*/

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) {
            return false;
        }

        return isContain(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool isContain(TreeNode* A, TreeNode* B) {
        if (B == nullptr) {
            return true;
        }

        if (A == nullptr || A->val != B->val) {
            return false;
        }

        return isContain(A->left, B->left) && isContain(A->right, B->right);
    }
};