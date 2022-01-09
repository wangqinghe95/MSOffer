#include<queue>
using namespace std;
/*
后序遍历，新的一层中最左边的先遍历到
最底层左边的值，区别去最底层最左的左子树值
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution_1 {
public:
    int findBottomLeftValue(TreeNode* root) {
        maxDepth = -1;
        dfs(root, 0);
        return res;
    }
private:
    void dfs(TreeNode* root, int depth) {
        if (nullptr == root) {
            return;
        }

        if (depth > maxDepth) {
            maxDepth = depth;
            res = root->val;
        }

        dfs(root->left, depth+1);
        dfs(root->right, depth+1);
    }
private:
    int res;
    int maxDepth;
};

/*
层次遍历，每层第一个被访问的值就是要求的值
*/
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        return levelTraversal(root);
    }
private:
    int levelTraversal(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            bool isFirst = true;
            for (int i = q.size(); i > 0; --i){
                TreeNode* cur = q.front();
                if (isFirst) {
                    res = cur->val;
                    isFirst = false;
                }
                q.pop();
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }

        return res;
    }
};