/*
    二叉树的路径求值
*/

/*
DFS：深度优先遍历
*/

#include"createTree.hpp"
#include<unordered_map>
#include<algorithm>
class Solution_DFS {
public:
    void DFS(TreeNode* root, vector<int> &path,const int target) {
        if (root == nullptr) {
            return;
        }
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && getSum(path, target)) {
            res.push_back(path);            
        }        

        DFS(root->left, path, target);
        DFS(root->right, path, target);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> path;
        DFS(root, path, target);
        return res;
    }
public:
    vector<vector<int>> res;
private:
    bool getSum(vector<int>& path, const int target) {
        int sum = 0;
        for (int i = 0; i < path.size(); ++i) {
            sum += path[i];
        }
        return sum == target;
    }
};


/*
    BFS：广度优先搜索
*/

class Solution_BFS {

public:
    vector<vector<int>> res;
    unordered_map< TreeNode*, TreeNode*> parent_node;
    void getPath( TreeNode* node) {
        vector<int> tmp;
        while (node != nullptr)
        {
            tmp.emplace_back(node->val);
            node = parent_node[node];
        }

        reverse(tmp.begin(), tmp.end());
        res.emplace_back(tmp);        
    }
    vector<vector<int>> BFS( TreeNode* root,const int target) {
        queue< TreeNode*> que_node;
        queue<int> que_sum;

        que_node.emplace(root);
        que_sum.emplace(0);

        while (!que_node.empty())
        {
            TreeNode* now = que_node.front();
            que_node.pop();

            int rec = que_sum.front() + now->val;
            que_sum.pop();

            if (now->left == nullptr && now->right == nullptr) {
                if (target == rec) {
                    getPath(now);
                }
            }
            if (now->left != nullptr) {
                que_node.emplace(now->left);
                que_sum.emplace(rec);
                parent_node[now->left] = now;
            }
            if (now->right != nullptr) {
                que_node.emplace(now->right);
                que_sum.emplace(rec);
                parent_node[now->right] = now;
            } 

        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        return BFS(root, target);
    }
};

int main() {
    return 0;
}