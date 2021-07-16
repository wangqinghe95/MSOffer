/* 
 * 迭代实现
 */

class Solution {
public:
    bool check(TreeNode*u, TreeNode* v) {
        queue<TreeNode*> q;
        q.push(u);
        q.push(v);

        while (!q.empty()) {
            TreeNode* now1 = q.front(); q.pop();
            TreeNode* now2 = q.front(); q.pop();

            if (!now1 && !now2) {
                 continue;
            }

            if ((!now2 || !now1) || (now1->val != now2->val)) {
                return false;
            }

            q.push(now1->left);
            q.push(now2->right);

            q.push(now1->right);
            q.push(now2->left);
        }

        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

/* 
 * 递归实现
 */

class Solution {
public:
    bool check(TreeNode* q, TreeNode* p) {
        if (!q && !p) {
            return true;
        }
        if (!q || !p) {
            return false;
        }

        return q->val == p->val && check(q->left, p->right) && check(q->right, p->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};