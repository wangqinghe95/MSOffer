
/*
    hash方法
*/


 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, bool> hash;
        ListNode* Node = headA;
        while(Node != NULL) {
            hash[Node] = true;
            Node = Node->next;
        }

        ListNode* result = NULL;
        Node = headB;
        while (Node != NULL) {
            if (hash[Node] == true) {
                return Node;
            }
            Node = Node->next;
        }

        return NULL;
    }
};

// 双指针
// 两个指针走完两个链表，肯定会在交互处碰面，相等，否则就是两个指针走完链表双双为空
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL ) {
            return NULL;
        }
        
        ListNode* pA = headA;
        ListNode* pB = headB;
        while (pA != pB) {
            pA = pA == NULL ? headB : pA->next;
            pB = pB == NULL ? headA : pB->next;
        }

        return pA;
    }
};

