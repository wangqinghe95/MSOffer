#include<iostream>
#include<unordered_map>
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
前缀和+深度优先遍历
*/
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return getTargetPathSum(root, 0, targetSum);
    }
private:
    int getTargetPathSum(TreeNode* root, int curr, int target) {
        if (nullptr == root) {
            return 0;
        }

        int ret = 0;
        curr += root->val;
        if (prefix.count(curr-target)) {
           ret = prefix[curr-target]; 
        }

        prefix[curr]++;
        ret += getTargetPathSum(root->left, curr, target);
        ret += getTargetPathSum(root->right, curr, target);
        prefix[curr]--;

        return ret;
    }
private:
    unordered_map<long long, int> prefix;
};
/*
    暴力破解，将每个节点都当作是根节点去找它的子树中有没有符合条件的路径
    因为值是可以有正有负的情况，所以无法剪枝
*/
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (nullptr == root) {
            return 0;
        }
        int ret = getSumNum(root, targetSum);
        ret += pathSum(root->left,targetSum);
        ret += pathSum(root->right, targetSum);
        return ret;
    }
private:
    int getSumNum(TreeNode* root, int target) {
        if (nullptr == root) {
            return 0;
        }

        int ret = 0;
        if (root->val == target) {
           ret++; 
        }

        ret += getSumNum(root->left, target - root->val);
        ret += getSumNum(root->right, target - root->val);
        return ret;
    }
};