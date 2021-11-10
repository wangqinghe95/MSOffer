#include"createTree.hpp"

/**
 * 1.找中点
 * 2.逆序后半点链表
 * 3.合并两个链表
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *mid = findListNodeMid(head);
        ListNode* tail = reverseList(mid->next);
        mid->next = nullptr;

        ListNode* res = head;

        // 1->2->3->null  5->4->nullptr
        // 1->5->2->4->3
        while (head && tail) {
            ListNode* tail_next = tail->next;
            ListNode* head_next = head->next;
            tail->next = head->next;
            head->next = tail;

            tail = tail_next;
            head = head_next;
        }


    }
private:
    // 1->2->3->4->null
    // slow = 1, fast = 1
    // slow = 2, fast = 2, fast = 3
    // fast = 4, slow = 3, fast = 5
    ListNode* findListNodeMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
            if (fast->next) {
                fast = fast->next;
            }
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }

};