#include<vector>
#include<stack>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<string>& matrix) {
        int m = matrix.size();
        if (0 == m) {
            return 0;
        }
        int n = matrix[0].size();
        if (0 == n) {
            return 0;
        }

        auto max = [](int x, int y){ return x > y ? x : y;};
        vector<int> height(n);
        int maxArea = 0;
        for (int i = 0; i < m; ++i) { 
            for (int j = 0; j < n; ++j) {
                if ('1' == matrix[i][j]) {
                    height[j]++;
                }
                else {
                    height[j] = 0;
                }
            }
            maxArea = max(maxArea, getMax(height));
        }
        return maxArea; 
    }
private:
    int getMax(vector<int> vec) {
        vec.emplace_back(0); // 在末尾加一个0是为了将栈中的元素都给弄出栈
        stack<int> st;
        st.push(-1);
        int res = 0;
        for (int i = 0; i < vec.size(); ++i) {
            if (-1 == st.top()) {
                st.push(i);
            }
            else {
                if (vec[i] >= vec[st.top()]) {
                    st.push(i);
                }
                else {
                    while(-1 != st.top() && vec[i] < vec[st.top()]) {
                       int h = vec[st.top()];
                       st.pop();
                       int w = i - st.top() - 1; 
                        res = max(res, h*w);
                    }
                    st.push(i);
                }
            }
        }
        return res;
    }
};

int main() {
    vector<string> matrix{"10100","10111","11111","10010"};
    Solution a;
    cout << a.maximalRectangle(matrix) << endl;
    return 0;
}