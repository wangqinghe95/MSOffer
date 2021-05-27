#include <iostream>
#include <stack>

using namespace std;

class CQueue {
private:
    stack<int> st1, st2;
public:
    CQueue() {
        while (!st1.empty())
        {
            st1.pop();
        }
        while (!st2.empty())
        {
            st2.pop();
        }        
    }
    
    void appendTail(int value) {
        st1.push(value);
    }
    
    int deleteHead() {
        if (st1.empty() && st2.empty()){
            return -1;
        }
        else if (st2.empty()){
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }            
        }

        int deleteItem = st2.top();
        st2.pop();
        return deleteItem;
    }
};

int main(){

}