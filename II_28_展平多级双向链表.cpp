#include"createTree.hpp"
#include<vector>
#include<stack>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

/**
 * @brief 前序遍历，将所有节点都放到一个数组中，然后数组一个一个数组组合成一个链表
 * 
 */
class Solution {
public:
    Node* flatten(Node* head) {
        preOrder(head);

        for (int i = 0; i < vec.size(); ++i) {
            if (i != 0) {
                vec[i]->prev = vec[i-1];
            }
            if (vec[i]->child) {
                vec[i]->child = nullptr;
            }

            if (i < vec.size() - 1) {
                vec[i]->next = vec[i+1];
            }
        }

        return head;
    }
private:
    void preOrder(Node* head) {
        if (!head) {
            return;
        }

        vec.push_back(head);
        preOrder(head->child);
        preOrder(head->next);
    }
private:
    vector<Node*> vec;
};

/**
 * @brief 如果将child 的节点看作树的左子树，next节点看作是树的右子树，那么这就是一道树的后续遍历
 * @details 
 */
class Solution {
public:
    Node* flatten(Node* head) {
        preOrder(head);
        return head;
    }

private:
    void preOrder(Node* head) {
        if (!head) {
            return;
        }

        preOrder(head->next);
        preOrder(head->child);

        head->next = pre;
        if (pre) {
            pre->prev = head;
        }
        head->child = nullptr;

        pre = head;    
    }

private:
    Node* pre = nullptr;
};


/**
 * @brief 栈保存
 * @details
 * 将有孩子的后续节点保存下来，继续去遍历孩子节点
 * 当当前节点的next为空，但是栈为空时，将栈的顶节点拿出来当下个节点放到当前节点的next中
 * 如果next为空，并且栈结构也空，说明遍历完了
 */
class Solution_stack {
public:
    Node* flatten(Node* head) {
        stack<Node*> vec_child;
        Node* res = head;
        while(head) {
            if (head->child) {
                if (head->next) {
                    vec_child.push(head->next);
                }

                head->next = head->child;
                head->child = nullptr;
                head->next->prev = head;
            }

            if (!head->next && !vec_child.empty()) {
                Node* tmp = vec_child.top();
                vec_child.pop();

                head->next = tmp;
                tmp->prev = head;
            }

            head = head->next;
        }

        return res;
    }
};