

// 用数组存储节点的值
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        index = 0;
        preOrder(root);
    }
    
    int next() {
        return res[index++];
    }
    
    bool hasNext() {
        if (index < res.size()) {
            return true;
        }
        else {
            return false;
        }
    }
private:
    void preOrder(TreeNode* root) {
        if (nullptr == root) {
            return;
        }

        preOrder(root->left);
        res.push_back(root->val);
        preOrder(root->right);
    }
private:
    vector<int> res;
    int index;
};

// 迭代实现中序遍历
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        mRoot = root;
    }
    
    int next() {
        while (mRoot) {
            stk.push(mRoot);
            mRoot = mRoot->left;
        }

        mRoot = stk.top();
        stk.pop();
        int ret = mRoot->val;
        mRoot = mRoot->right;
        return ret;
    }
    
    bool hasNext() {
        return (mRoot != nullptr || !stk.empty());
    }
private:
    TreeNode* mRoot;
    stack<TreeNode*> stk;
};