class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        while(!data_stk.empty()) {
            data_stk.pop();
        }
        while(!min_stk.empty()) {
            min_stk.pop();
        }
    }
    
    void push(int x) {
        data_stk.push(x);
        if (min_stk.empty()) {
            min_stk.push(x);
        }
        else {
            if (x > min_stk.top()) {
                min_stk.push(min_stk.top());
            }
            else {
                min_stk.push(x);
            }
        }
    }
    
    void pop() {
        if (!data_stk.empty()) {
            data_stk.pop();
            min_stk.pop();
        }
    }
    
    int top() {
        return data_stk.top();
    }
    
    int min() {
        return min_stk.top();
    }
private:
    stack<int> data_stk;
    stack<int> min_stk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */