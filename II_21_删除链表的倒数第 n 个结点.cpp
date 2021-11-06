
// 1 2 3 4 5
// 2
// 2->1 front = 2   1=>0 front = 3
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution_1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode* front = head;
        while(n-- && front) {
            front = front->next;
        }

        if (!front){
            return head->next;
        }

        ListNode* rear = head;
        ListNode* pre = nullptr;
        while(front) {
            front = front->next;
            pre = rear;
            rear = rear->next;
        }

        pre->next = pre->next->next;

        return head;
    }
};

//哨兵指针
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = head;
        while(n--) {
            fast = fast->next;
        }

        ListNode* slow = dummy;
        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return dummy->next;
    }
};