#include<vector>
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// heap sort

// merge sort
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return nullptr;
        }
        return mergeLists(lists, 0, lists.size() - 1);
    }
private:
    ListNode* mergeLists(vector<ListNode*> &lists,const int start,const int end) {
        if (start == end){
            return lists[start];
        }
        int mid = start + ((end - start) >> 1);
        ListNode* head1 = mergeLists(lists, start, mid);
        ListNode* head2 = mergeLists(lists, mid+1, end);
        return merge(head1, head2);
    }
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while(head1 != nullptr && head2 != nullptr) {
            if (head1->val > head2->val) {
                cur->next = head2;
                head2 = head2->next;
            }
            else{
                cur->next = head1;
                head1 = head1->next;
            }
            cur = cur->next;
        }

        cur->next = head1 != nullptr ? head1 : head2;

        ListNode* ret = dummy->next;
        delete dummy;
        dummy = nullptr;
        return ret;
    }
};

int main()
{

}
