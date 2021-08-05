
/*
中序遍历二叉树，树的右结点指向下一个结点（中序遍历的下一个子结点）
左子树指向上一个结点。
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) {
            return NULL;
        }

        DFS(root);
        head->left = pre;
        pre->right = head;
        return head;a
    }
private:
    Node* pre, *head;
    void DFS(Node* node) {
        if (node == NULL) {
            return ;
        }

        DFS(node->left);

        if (pre != NULL) {
            pre->right = node;
        }
        else {
            head = node;
        }

        node->left = pre;
        pre = node;

        DFS(node->right);
    }
};

