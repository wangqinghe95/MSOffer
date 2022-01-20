
// 迭代方式的中序遍历
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        bool flag = false;
        while(!st.empty() || cur) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }

            TreeNode* u = st.top();
            st.pop();
            if (flag) {
                return u;
            }

            if (u == p) {
                flag = true;
            }

            cur = u->right;
        }
        return NULL;
    }
};
// 递归的方式遍历的记录前一个变量
class Solution_2 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bIsFindPInTree = false;
        resNode = NULL;
        inOrder(root, p);
        return resNode;
    }
private:
    void inOrder(TreeNode* root, TreeNode* p) {
        if (!root) {
            return;
        }

        inOrder(root->left, p);
        if (bIsFindPInTree) {
            if (NULL == resNode) {
                resNode = root;
            }
            return;
        }
        if (root->val == p->val) {
            bIsFindPInTree = true;
        }

        inOrder(root->right, p);
    }
private:
    bool bIsFindPInTree;
    TreeNode* resNode;
};


// 利用二叉树的性质
// 如果当前的节点大于p点的值，就去当前节点的左子树继续去找同样大于p但是小于当前值的节点
// 如果当前的值小于p点的值，就去该节点的右子树去找大于p点的值
class Solution_1 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res = NULL;
        while (NULL != root) {
            if (root->val > p->val) {
                res = root;
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        return res;
    }
};