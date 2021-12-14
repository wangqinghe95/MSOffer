#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/**
 * @brief 
 * @details 1. 只有正数在前，负数在后才会有抵消
 *          2. 进栈条件：
 *              1. 栈为空时当前数字进栈；
 *              2. 当前数字和栈顶元素同号时进栈;
 *              3. 当前数字为正时进栈；
 */
// 异或：不同为1，相同为0
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        int index = 0;
        /*
        while (index < asteroids.size() && asteroids[index] < 0)
        {
            st.push_back(asteroids[index++]);
        }
        while (index < asteroids.size() && asteroids[index] > 0)
        {
            st.push_back(asteroids[index++]);
        }*/
        
        
        while (index < asteroids.size()) {
             if (!st.empty() && st.back() > 0 && asteroids[index] * st.back() < 0) {
                int a = abs(asteroids[index]);
                int b = abs(st.back());
                if (a > b) {
                    st.pop_back();
                }
                else if (a < b) {
                    index++;
                }
                else {
                    st.pop_back();
                    index++;
                }
            }
            else {
                st.push_back(asteroids[index++]);
            }
        }

        return st;
    }
};

int main() {
    // vector<int> aster{-2,-1,1,2};
    vector<int> aster{5,10,-3};
    Solution a;
    a.asteroidCollision(aster);
    return 0;
}