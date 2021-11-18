#include"createTree.hpp"

/**
 * @brief 向一个非递减的链表中插入一个节点使之继续保持非递减状态
 * @details 插入的位置情况有：
 *          1. 大于当前节点值而小于后一节点的值
 *          2. 在边界情况下，大于当前节点值（大于该链表所有节点值），小于下一个节点值（小于该链表所有节点）
 */         

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == NULL) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }

        Node* cur = head;
        while (cur->next != head) {
            if (cur->val < insertVal && cur->next->val >= insertVal) {
                break;
            }

            if (cur->val > cur->next->val) {
                if (cur->val < insertVal) {
                    break;
                }
                if (cur->next->val >= insertVal) {
                    break;
                }
            }
            cur = cur->next;
        }

        Node* tmp = new Node(insertVal, cur->next);
        cur->next = tmp;
        return head;
    }
};

int main() {
    Node* head = new Node(1,nullptr);
}