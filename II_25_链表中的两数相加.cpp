#include"createTree.hpp"

// res -> node
//     tmp 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode* res = new ListNode(-1 ,nullptr);
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int val_1 = l1 ? l1->val : 0;
            int val_2 = l2 ? l2->val : 0;
            int tmp = carry + val_1 + val_2;
            carry = tmp / 10;

            ListNode* tmp_node = new ListNode(tmp%10, res->next);
            res->next = tmp_node;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        return res->next;             
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

// 在原有的链表上增减太过麻烦了这种方法舍弃了
class Solution_1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode* longer = l1->val > l2->val ? l1 : l2;
        ListNode* shorter = l1->val > l2->val ? l2 : l1;

        ListNode* res = longer;

        int carry = 0;
        while (shorter->next) {
            longer = longer->next;
            shorter = shorter->next;

            int tmp = carry + shorter->val + longer->val;
            carry = tmp / 10;
            longer->val = tmp % 10;
        }

        if (carry != 0) {
            if (!longer->next){
                longer->next = new ListNode(carry,nullptr);
            }
            else {
                longer->val += carry;
            }
        }

        return reverseList(res)->next;
    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;

        int cnt = 0;
        while(cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            cnt++;
        }

        ListNode* res = new ListNode(cnt, pre);
        return res;
    }
};

int main() {
    ListNode* l1 = new ListNode(5, nullptr);
    ListNode* l2 = new ListNode(7, nullptr);
    Solution a;
    ListNode* head = a.addTwoNumbers(l1, l2);
    return 0;
}