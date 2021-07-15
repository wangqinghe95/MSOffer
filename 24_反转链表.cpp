/*
 * @Description: 
 * @Version: 2.0
 * @Autor: wanghao
 * @Date: 2021-07-15 17:25:08
 * @LastEditors: wanghao
 * @LastEditTime: 2021-07-15 17:25:17
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur != NULL) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};
