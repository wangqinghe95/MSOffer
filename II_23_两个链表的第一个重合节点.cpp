#include<unordered_set>
#include"createTree.hpp"

using namespace std;

/*
Hash
*/
class Solution_Hash {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> visited;
        while(headA) {
            visited.insert(headA);
            headA = headA->next;
        }

        while (headB)
        {
            if (visited.count(headB)) {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};

/*
思路：找到两根链表的长度差值，然后长的链表先走长度差，然后长链表和短链表一直往前走
    这样如果两个链表的节点是相同的，那么就说明找到了公共节点，否则走到尾也没有找到，就说明没有相同的节点
*/

class Solution_disGap {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int disGap = 0;
        ListNode* tmpA = headA;
        while(tmpA) {
            tmpA = tmpA->next;
            disGap++;
        }

        ListNode* tmpB = headB;
        while(tmpB) {
            tmpB = tmpB->next;
            disGap--;
        }

        if (disGap > 0) {
            return searchSameNode(headA, headB, disGap);
        }
        else {
            return searchSameNode(headB, headA, -disGap);
        }
    }
private:
    ListNode* searchSameNode(ListNode* longer, ListNode* shorter, int disGap) {
        while(disGap--){
            longer = longer->next;
        }

        while(longer && longer != shorter) {
            longer = longer->next;
            shorter = shorter->next;
        }

        return longer ? shorter : nullptr;
    }
};

/*
思路：两根指针都走了两个链表前半截不一样长度和后面相同的节点的长度
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode* tmpA = headA;
        ListNode* tmpB = headB;

        while (tmpA != tmpB) {
            tmpA = tmpA == nullptr ? headB : tmpA->next;
            tmpB = tmpB == nullptr ? headA : tmpB->next;
        }   

        return tmpA;     
    }
};