#include <stack>
#include <iostream>
#include <queue>
#include <vector>
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

class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        mRoot = root;
        mTreeSize = getTreeSize(mRoot);
    }
    
    int insert(int v) {
        TreeNode* insertNodeParent = getInsertNodeParent(mTreeSize);
        if (nullptr == insertNodeParent->left) {
            insertNodeParent->left = new TreeNode(v);
        }
        else {
            insertNodeParent->right = new TreeNode(v);
        }
        return insertNodeParent->val;
    }
    
    TreeNode* get_root() {
        return mRoot;
    }
private:
    TreeNode* getInsertNodeParent(int treeSize) {
        stack<int> st;
        while (treeSize > 0) {
            treeSize = (treeSize - 1)/2;
            st.push(treeSize);
        }

        TreeNode* resNode = mRoot;
        st.pop();
        while (!st.empty())
        {
            int cur = st.top();
            st.pop();
            if (0 == cur%2) {
                resNode = resNode->right;
            }
            else {
                resNode = resNode->left;
            }
        }

        return resNode;
        
    }
    int getTreeSize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while (!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            res++;
            if (cur->left) {
                q.push(cur->left);
            } 
            if (cur->right) {
                q.push(cur->right);
            }
        }
        return res; 
    }
private:
    TreeNode* mRoot;
    TreeNode* mInsertNextNodeParent;
    int mTreeSize;
};

class CBTInserter_2 {
public:
    CBTInserter_2(TreeNode* root) {
       setCBTArr(root);
    }
    
    int insert(int v) {
        CBTArr.push_back(new TreeNode(v));
        return CBTArr[(CBTArr.size()-2)/2]->val;
    }
    
    TreeNode* get_root() {
        return CBTArr[0];
    }
private:
    void setCBTArr(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            CBTArr.push_back(node);
            if (node->left){
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }
private:
    vector<TreeNode*> CBTArr;
};

class CBTInserter_1
{
public:
    CBTInserter_1(TreeNode *root)
    {
        mRoot = root;
        mInsertNextNode = getInsertNode(mRoot);
    }

    int insert(int v)
    {
        int res = mInsertNextNode->val;
        if (mInsertNextNode->left == nullptr) {
            mInsertNextNode->left = new TreeNode(v);
        }
        else {
            mInsertNextNode->right = new TreeNode(v);
            mInsertNextNode = getInsertNode(mRoot);
        }
        return res;
    }

    TreeNode *get_root()
    {
        return mRoot;
    }
private:
    TreeNode* getInsertNode(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left && cur->right) {
                q.push(cur->left);
                q.push(cur->right);
            }
            else {
                return cur;
            }
        }
        return nullptr;
    }

private:
    TreeNode *mRoot;
    TreeNode *mInsertNextNode;
};

int main() {
    TreeNode* root = new TreeNode(1);
    CBTInserter* obj = new CBTInserter(root);
    cout << obj->insert(2) << endl;
    return 0;
}