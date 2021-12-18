#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
    单调栈
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> st;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int index = st.top();
                st.pop();
                res[i] = i - index;
            }

            st.push(i);
        }

        return res;
    }
};
/*
*   1. 如果前一个数小于后一个数：
        1. 后一个数可以直接设为 1
    2. 如果前一个数大于后一个数：
        1. 如果后一个数的res值为0，则该值也为0；
        2. 如果寻找后面第一个大于该数的index

    时间复杂度超了
*/
class Solution_1 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        if (temperatures.size() <= 1) {
            return res;
        }
        int last_max = temperatures[temperatures.size()-1];
        int last_max_index = temperatures.size() - 1;
        for (int i = temperatures.size()-2; i >= 0; --i) {
            if (temperatures[i] > last_max) {
                res[i] = 0;
                last_max = temperatures[i];
                last_max_index = i;
            }
            else if (temperatures[i] < temperatures[i+1]){
                res[i] = 1;
            }
            else {
                for (int j = i+2; j <= last_max_index; ++j){
                    if(temperatures[j] > temperatures[i]) {
                        res[i] = j - i;
                        break;
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    vector<int> temperature{73,74,75,71,69,72,76,73};
    Solution a;
    a.dailyTemperatures(temperature);
    return 0;
}