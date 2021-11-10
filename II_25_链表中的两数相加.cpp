#include"createTree.hpp"
#include<stack>
using namespace std;


/**
 * 辅助栈实现从尾到头的逆序
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> que_1;
        stack<ListNode*> que_2;

        addStack(que_1, l1);
        addStack(que_2, l2);

        ListNode* head = new ListNode(-1, nullptr);
        int carry = 0;
        while (!que_1.empty() || !que_2.empty() || carry != 0) 
        {
            carry = getTopStk(que_1) + getTopStk(que_2) + carry;

            ListNode* tmp = new ListNode(carry%10, head->next);
            head->next = tmp;

            carry /= 10;
        }

        return head->next;
        
    }
private:
    int getTopStk(stack<ListNode*> &q) {
        if (q.empty()) {
            return 0;
        }

        int val = q.top()->val;
        q.pop();
        return val;        
    }

    void addStack(stack<ListNode*> &q, ListNode* head) {
        while (head) {
            q.push(head);
            head = head->next;
        }
    }
};

// res -> node
//     tmp 
class Solution_2 {
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