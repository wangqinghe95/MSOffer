/*
双指针找倒数第k个节点
*/

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL) {
            if (k > 0) {
                fast = fast->next;
                k--;
            }
            else {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
};