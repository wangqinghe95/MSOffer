/*
构造头结构法，这样就可以避免去判断删除的节点是否是头结点的情况
*/


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *pre = new ListNode;
        pre->next = head;
        ListNode* visNode = pre;
        while (visNode->next != NULL){
            if (val == visNode->next->val){
                visNode->next = visNode->next->next;
                break;
            }
            visNode = visNode->next;
        }

        return pre->next;
    }
};

// 单独判断头节点
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val){
            return head->next;
        }

        ListNode* visNode = head;
        while(visNode->next){
            if (visNode->next->val == val){
                visNode->next = visNode->next->next;
                break;
            }
            visNode = visNode->next;
        }

        return head;
    }
};

// 递归
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val){
            return head->next;
        }

        head->next = deleteNode(head->next, val);
        return head;
    }
};