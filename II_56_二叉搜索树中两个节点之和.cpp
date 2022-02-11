
#include<vector>
#include<stack>
#include<unordered_set>
using namespace std;

// 求一颗二叉搜索树上是否有两个节点的和为一个定值
// 首先中序遍历是一个有序的数组
// 一个有序的数组找是否有两个数的和是否等于一个定值

/**
 * Definition for a binary tree node.
 */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution_1 {
public:
    bool findTarget(TreeNode* root, int k) {
        inOrder(root);

        int i = 0; 
        int j = mArr.size() - 1;
        while (i < j) {
            if (mArr[i] + mArr[j] == k) {
                return true;
            }
            else if (mArr[i] + mArr[j] > k) {
                j--;
            }
            else {
                i++;
            }
        }

        return false;
    }
private:
    void inOrder(TreeNode* root) {
        if (nullptr == root) {
            return;
        }

        inOrder(root->left);
        mArr.push_back(root->val);
        inOrder(root->right);
    }
private:
    vector<int> mArr;
};

// 使用迭代的中序遍历方式
class Solution_2 {
public:
    bool findTarget(TreeNode* root, int k) {
        if (nullptr == root) {
            return false;
        }

        unordered_set<int> nums;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(cur != nullptr || !stk.empty()) {
            while(cur != nullptr) {
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top();
            stk.pop();
            if (nums.count(k-cur->val)) {
                return true;
            }
            nums.insert(cur->val);
            cur = cur->right;
        }

        return true;
    }
};

// 在遍历过程中进行大小数值的判断，采用的是双指针
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (nullptr == root) {
            return false;
        }

        mLeftRoot = root;
        mRightRoot = root; 
        int left = leftTrave();
        int right = rightTrave();
        while(left < right) {
            if (left + right == k) {
                return true;
            }
            else if (left+right > k) {
                right = rightTrave();
            }
            else {
                left = leftTrave();
            }
        }

        return false;
    }
private:
    int leftTrave(){
        while(mLeftRoot) {
            stkLeft.push(mLeftRoot);
            mLeftRoot = mLeftRoot->left;
        }

        mLeftRoot = stkLeft.top();
        stkLeft.pop();
        int rett = mLeftRoot->val;
        mLeftRoot = mLeftRoot->right;
        return rett;
    }

    int rightTrave(){
        while(mRightRoot) {
            stkRight.push(mRightRoot);
            mRightRoot = mRightRoot->right;
        }
        
        mRightRoot = stkRight.top();
        stkRight.pop();
        int rett = mRightRoot->val;
        mRightRoot = mRightRoot->left;
        return rett;
    }
private:
    TreeNode* mLeftRoot;
    TreeNode* mRightRoot;
    stack<TreeNode*> stkLeft;
    stack<TreeNode*> stkRight;
};