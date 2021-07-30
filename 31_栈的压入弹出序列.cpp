#include<iostream>
#include<vector>

#include<stack>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int index_pop = 0;
    int index_pushed = 0;
    while (index_pushed < pushed.size())
    {
        st.push(pushed[index_pushed++]);
        while (!st.empty() && st.top() == popped[index_pop]) {
            st.pop();
            index_pop++;
        }
    }

    if(st.empty() && index_pushed == pushed.size()){
        return true;
    }
    else {
        return false;
    }
    
}

int main(){
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,3,5,1,2};
    // vector<int> popped = {4,5,3,2,1};
    cout << validateStackSequences(pushed, popped) << endl;
    return 0;
}