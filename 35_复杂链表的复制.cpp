/*
 复杂链表的复制，主要是对于random指针的复制。random指针可能随机指向整个链表的所有结点
 所以至少需要两次遍历
*/

/*
 使用hash来标记复制的链表和原链表的对应关系，用于复制指向random的指针指向
*/
#include<unordered_map>
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> mp;

        Node* cur = head;
        while (cur != NULL) {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while(cur != NULL) {
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }

        return mp[head];
    }
};

/*
    复制、拆分
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        Node* cur = head;
        while (cur != NULL) {
            Node* tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }

        cur = head;
        while(cur != NULL) {
            if (cur->random != NULL) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        cur = head->next;
        Node* pre = head, *res = head->next;
        while(cur->next != NULL) {
            pre->next = pre->next->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }

        pre->next = NULL;
        return res;
    }
};