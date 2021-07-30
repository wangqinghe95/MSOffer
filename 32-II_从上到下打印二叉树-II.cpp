#include<iostream>
#include<vector>
#include<queue>

#include"createTree.hpp"

using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == NULL) {
        return {};
    }

    vector<vector<int>> res;
    vector<int> tmp;
    queue<TreeNode*> q;
    q.push(root);

    TreeNode* last_tree = NULL;
    TreeNode* next_last_node = root;
    while (!q.empty()) {
        TreeNode* now = q.front();
        q.pop();

        tmp.push_back(now->val);

        if (now->left != NULL) {
            q.push(now->left);
            last_tree = now->left;
        }

        if (now->right != NULL) {
            q.push(now->right);
            last_tree = now->right;
        }

        if (now == next_last_node) {
            next_last_node = last_tree;
            res.push_back(tmp);
            tmp.clear();
        }
    }

    return res;
}

namespace offer_32 {
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        int index = 0;

        while (!q.empty())
        {
            res.push_back(vector<int>());
            for (int i = q.size(); i > 0; --i){
                TreeNode* now = q.front();
                q.pop();

                res[index].push_back(now->val);
                if (now->left != nullptr) {
                    q.push(now->left);
                }
                if (now->right != nullptr) {
                    q.push(now->right);
                }
            }
            index++;
        }
        return res;
    }
};
}

int main() {
    vector<int> arr = {3, 9, 20, -1, -1, 15, 7};
    TreeNode* root = createTree(arr);
    offer_32::Solution a;
    vector<vector<int>> res = a.levelOrder( root);
    return 0;
}