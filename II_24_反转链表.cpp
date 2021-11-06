

#include"createTree.hpp"

/*
原地反转：迭代
*/
class Solution_iterator {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};

/*
递归
*/

// 1 2 3 4 5
// 1 2 3->4->5 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;    // 将当前节点的后一个节点的next指向自身
        head->next = nullptr;       // 将当前节点的next指向nullptr，非最后一个节点的next都会在上一个节点的递归后被修正
        return newHead;
    }
};