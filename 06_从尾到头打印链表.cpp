/*
方法1：递归
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void reverse(ListNode* node, vector<int>& res)
    {
        if (node == NULL){
            return;
        }

        reverse(node->next, res);
        res.push_back(node->val);
    }
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        reverse(head, res);
        return res;
    }
};

//方法2：迭代

vector<int> reversePrint(ListNode* head) {
    stack<int> st;
    vector<int> res;
    while(head != NULL){
        st.push(head->val);
        head = head->next;
    }

    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }

    return res;
}