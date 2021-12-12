#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const string &str : tokens) {
            if (isNumber(str)) {
                st.push(getNumberByString(str));
            }
            else {
                calcNumber(str[0], st);
            }
        }

        return st.top();
    }
private:
    void calcNumber(const char& c, stack<int>& st) {
        int num_1 = st.top();
        st.pop();
        int num_2 = st.top();
        st.pop();
        int num_3 = -1;

        switch (c)
        {
        case '+':
            num_3 = num_1 + num_2; 
            break;
        
        case '-':
            num_3 = num_2 - num_1; 
            break;
        case '*':
            num_3 = num_1 * num_2; 
            break;
        case '/':
            num_3 = num_2 / num_1; 
            break;
        default:
            break;
        }

        st.push(num_3);
    }
    bool isNumber(const string& str) {
        if (str.size() > 1) {
            return true;
        }
        const char &c = str[0];
        if (c >= '0' && c <= '9') {
            return true;
        }
        else {
            return false;
        }
    }

    int getNumberByString(const string& str) {
        int number = 0;
        int flag = 1;
        int index = 0;
        if (str[0] == '-') {
           flag = -1; 
           index = 1;
        }
        for (int i = index; i < str.size(); ++i) {
            if (str[i] >= '0' && str[i] <= '9') {
                number = number * 10 + (str[i] - '0');
            }
        }
        return number * flag;
    }
};

int main() {
    // vector<string> tokens{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    vector<string> tokens{"4", "3", "-"};
    Solution a;
    cout << a.evalRPN(tokens) << endl;
    return 0;
}
