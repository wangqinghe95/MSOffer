#include<iostream>
#include<queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 后序遍历的变形-根右左
class Solution_post {
public:
    vector<int> rightSideView(TreeNode* root) {
        maxDepth = -1;
        vector<int> res;
        dfs(root, res, 0);
        return res;
    }
private:
    void dfs(TreeNode* root, vector<int>& res, int depth) {
       if (nullptr == root) {
           return;
       }
        if (depth > maxDepth) {
            res.push_back(root->val);
            maxDepth = depth;
        }
        dfs(root->right, res, depth+1);
        dfs(root->left, res, depth+1);
    }
private:
    int maxDepth;
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (nullptr == root) {
            return vector<int>{};
        }
        vector<int> res;
        levelTraverse(root, res);
        return res;
    }
private:
    void levelTraverse(TreeNode* root, vector<int>& res) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                TreeNode* cur = q.front();
                q.pop();
                if (1 == i) {
                    res.push_back(cur->val);
                }

                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }
    }
};