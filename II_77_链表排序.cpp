 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (nullptr == head || nullptr == head->next) {
            return head;
        }

        ListNode* head_first_begin = head;
        ListNode* head_second_begin = findListMid(head);

        head_first_begin = sortList(head_first_begin);
        head_second_begin = sortList(head_second_begin);

        return merge(head_first_begin, head_second_begin);
    }
private:
    ListNode* merge(ListNode* node_first, ListNode* node_second) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while(nullptr != node_first && nullptr != node_second) {
            if (node_first->val > node_second->val) {
                cur->next = node_second;
                node_second = node_second->next;
            }
            else {
                cur->next = node_first;
                node_first = node_first->next;
            }
            cur = cur->next;
        }

        cur->next = (node_first == nullptr ? node_second : node_first);
        ListNode* return_node = dummy->next;
        delete dummy;
        dummy = nullptr;
        return return_node;
    }

    ListNode* findListMid(ListNode* head){
        ListNode* fast_node = head->next;
        ListNode* slow_node = head;
        while(fast_node != nullptr && fast_node->next != nullptr){
            fast_node = fast_node->next->next;
            slow_node = slow_node->next;
        }

        ListNode* listMid = slow_node->next;
        slow_node->next = nullptr;
        return listMid;
    }
};

class Solution_1 {
public:
    ListNode* sortList(ListNode* head) {
        struct Node{
            int value;
            ListNode* cur_node;
        };

        auto cmp = [&](Node a, Node b) {
            return a.value < b.value;
        };

        vector<Node> node;
        ListNode *cur = head;
        while(cur != nullptr) {
            Node tmp;
            tmp.value = cur->val;
            tmp.cur_node = cur;
            node.push_back(tmp);
            cur = cur->next;
        }

        sort(node.begin(), node.end(),cmp);

        cur = nullptr;
        for (int i = 0; i < node.size(); ++i){
            cur = node[i].cur_node;
            if (i != node.size() - 1) {
                cur->next = node[i+1].cur_node;
            }
            else{
                cur->next = nullptr;
            }
        }

        return cur;
    }
};

int main()
{
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    Solution a;
    a.sortList(head);
    return 0;    
}