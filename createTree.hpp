#ifndef CREATETREE_HPP__
#define CREATETREE_HPP__

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* next;

    Node(){}
    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

TreeNode* newNode(int val) {
    if (val == -1) {
        return nullptr;
    }

    TreeNode* node = new TreeNode;
    node->left = nullptr;
    node->right = nullptr;
    node->val = val;
    return node;    
}

TreeNode* preOrder(TreeNode* node, const vector<int> &arr ,const int index) {
    if (index > arr.size() || arr[index] == -1) {
        return nullptr;
    }
    if (node == nullptr ) {
        node = newNode(arr[index]); 
    }
    node->left = preOrder(node->left, arr, index*2+1);
    node->right = preOrder(node->right, arr, index*2+2);
    return node;
}

TreeNode* createTree(const vector<int>& treeArr) {
    TreeNode* root = nullptr;
    preOrder(root, treeArr, 0);
    return root;
}

void inOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

#if 0
int main() {
    vector<int> arr = {3, 9, 20, -1, -1, 15, 7};
    TreeNode* root = createTree(arr);
    inOrder(root);
    return 0;
}
#endif

#endif