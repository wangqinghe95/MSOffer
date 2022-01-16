#include<vector>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int res = 0;
        vector<int> data;
        preOrder(root, data ,res);
        return res;
    }
private:
    void preOrder_1(TreeNode* root, int& sum, int& res) {
        sum = sum * 10 + root->val;
        if (nullptr == root->left && nullptr == root->right) {
            res += sum;
            sum /= 10;
            return;
        }

        if (nullptr != root->left) {
            preOrder_1(root->left, sum, res);
        }
        if (nullptr != root->right){
            preOrder_1(root->right, sum, res);
        }
        sum /= 10;    
    }
    void preOrder(TreeNode* root, vector<int>&data, int& res) {
        if (nullptr == root->left && nullptr == root->right) {
            data.push_back(root->val);
            int temp = 0;
            for (int i = 0; i < data.size(); ++i) {
                temp = temp * 10 + data[i];
            }
            res += temp;
            data.pop_back();
            return;
        }

        data.push_back(root->val);
        if (nullptr != root->left) {
            preOrder(root->left, data, res);
        }
        if (nullptr != root->right){
            preOrder(root->right, data, res);
        }
        data.pop_back();
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution a;
    cout << a.sumNumbers(root) << endl;
    return 0;
}