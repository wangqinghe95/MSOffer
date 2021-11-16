#include"createTree.hpp"

/**
 * @brief 
 * @attention 比较完节点之后，再将反转的中间节点到尾部节点再给反转回来
 *              目的就是为了保证不改变传入链表的节点
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid_node = findMinNode(head);
        ListNode* tail = reverseList(mid_node->next);
        // mid_node->next = nullptr; 

        // bool bisPalindrome = true;
        ListNode* head_copy = head;
        ListNode* tail_copy = tail;
        while (head_copy && tail_copy) {
            if (head_copy->val != tail_copy->val) {
                return false;
            }
            head_copy = head_copy->next;
            tail_copy = tail_copy->next;
        }

        // if (head || tail) {
        //     return false;
        // }

        mid_node->next = reverseList(tail);
        return true;
    }
private:
    ListNode* findMinNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
        
    }
    ListNode* reverseList(ListNode* head)
    {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};

/**
 * @brief 回文串链表
 * @method: 找到中间节点，然后反转，然后从头到中间节和尾部到中间比较
 * @attention: 从中间节点到尾部节点的反转后，然后直接从尾部节点到中间节点和首部到中间节点的比较
 *             不做最后一个节点的置空处理，但是改变的原有节点的结构
 */
class Solution_1 {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid_node = findMinNode(head);
        ListNode* tail = reverseList(mid_node->next);
        // mid_node->next = nullptr; 

        bool bisPalindrome = true;
        while (head && tail) {
            if (head->val != tail->val) {
                return false;
            }
            head = head->next;
            tail = tail->next;
        }

        // if (head || tail) {
        //     return false;
        // }

        return true;
    }

private:
    // 1 2 3 3 2 1
    // 1 1 2 3 3 1 
    // 1 2 3 2 1 
    // 1 1  2 2 2 2 20 
    ListNode* findMinNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next) {
            fast = fast->next;
            if (fast->next) {
                fast = fast->next;
                slow = slow->next;
            }
            else {
                ListNode* tmp = slow;
                slow = slow->next;
                tmp->next = nullptr;
            }
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};

int main() {
    ListNode* tmp1 = new ListNode(1, nullptr);
    ListNode* tmp2 = new ListNode(2, tmp1);
    ListNode* tmp3 = new ListNode(3, tmp2);
    ListNode* tmp4 = new ListNode(2, tmp3);
    ListNode* head = new ListNode(1, tmp4);

    Solution a;
    cout << a.isPalindrome(head) << endl;
    return 0;
}