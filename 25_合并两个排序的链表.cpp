/* 
    合并链表：迭代方式
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode;
    ListNode* copyHead = head;
    while (l1 && l2){
        if (l1->val > l2->val){
            head->next = l2;
            l2 = l2->next;
        }
        else {
            head->next = l1;
            l1 = l1->next;
        }
        head = head->next;
    }

    if (l1){
        head->next = l1;
    }
    if (l2){
        head->next = l2;
    }

    return copyHead->next;
}

/* 
 * 递归方式
 */

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1 || !l2) {
        return !l1 ? l2 : l1;
    }

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}