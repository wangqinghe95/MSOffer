#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        ret = INT_MIN;
        dfs(root);
        return ret;
    }
private:
    int dfs(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        ret = max(ret, left+right+root->val);
        return root->val + max(left,right);
    }
private:
    int ret;
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    Solution a;
    cout << a.maxPathSum(root) << endl;
    return 0;
}