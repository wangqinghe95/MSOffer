#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 右根左的遍历顺序
// 右根左的遍历方式就是中序遍历的左根右的镜像访问顺序
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        int sum = 0;
        while (!st.empty() || cur) {
            while (cur) {
                st.push(cur);
                cur = cur->right;
            }

            cur = st.top();
            st.pop(); 
            sum += cur->val;
            cur->val = sum;
            cur = cur->left;
        }
        return root;
    }
};
// 迭代方式
class Solution_1 {
public:
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        postOrder(root);
        return root;
    }
private:
    void postOrder(TreeNode* root) {
        if (nullptr == root) {
            return ;
        }
        postOrder(root->right);
        root->val = sum + root->val;
        sum = root->val;
        postOrder(root->left);
    }
private:
    int sum;
};