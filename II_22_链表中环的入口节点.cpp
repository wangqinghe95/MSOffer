#include"createTree.hpp"

/*
fast and slow point：self
how to find the first node when slow point is equal with fast point
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* front = head;
        ListNode* rear = head;
        while(front) {
            front = front->next;
            rear = rear->next;
            if (front){
                front = front->next;
            }
            else {
                return NULL;
            }
            if (front == rear) {
                ListNode* ptr = head;
                while(ptr != rear) {
                    ptr = ptr->next;
                    rear = rear->next;
                }
                return ptr;
            }
        }

        return NULL;
    }
};

/*
Code by others
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr)
        {
            slow = slow->next;
            if (fast->next == nullptr) {
                return nullptr;
            }

            fast = fast->next->next;
            if (fast == slow) {
                ListNode* ptr = head;
                while(ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }

        return nullptr;        
    }
};