#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

// 因为封装了一个函数，所以较方法2执行速度稍微慢了一点
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int maxArea = -1;
        auto max = [](int x, int y) { return x > y ? x : y;};
        for (int i = 0; i < heights.size(); ++i) {
            while(st.top() != -1 && heights[st.top()] > heights[i]) {
                maxArea = max(maxArea, handleMaxArea(st, heights, i));
            }
            st.push(i);
        }

        while (st.top() != -1) {
            maxArea = max(maxArea, handleMaxArea(st, heights, heights.size()));
        }

        return maxArea;
    }
public:
    int handleMaxArea(stack<int>& st, vector<int>& heights, int maxWidth) {
        int height = heights[st.top()];
        st.pop();
        int width = maxWidth - st.top() - 1;
        return height*width;
    }
};

class Solution_2 {
public:
    int largestRectangleArea(vector<int>& heights) {
       stack<int> st;
       st.push(-1);
       int maxArea = -1;
       //3,1,5,6,2,4
       // i 0 1 2 3 4 5
       // st -1 1 
       // height = 2
       // width = 4 
       // maxArea = 10  
       for (int i = 0; i < heights.size(); ++i){
           while (st.top() != -1 && heights[st.top()] > heights[i]) {
               int height = heights[st.top()];
               st.pop();
               int width = i - st.top() - 1;
               maxArea = max(maxArea, height*width);
           }
           st.push(i);
       }

       while(st.top() != -1) {
           int height = heights[st.top()];
           st.pop();
           int width = heights.size() - st.top() - 1;
           maxArea = max(maxArea, height*width);
       }
       return maxArea;
    }
};
class Solution_1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() <= 1) {
            return heights[0];
        }
        auto max = [](int x, int y) {return x > y ? x : y;};
        auto min = [](int x, int y) {return x > y ? y : x;};

        int i = heights.size()/2-1;
        int j = i+1;
        int nMaxArea = -1;
        int nMinHeight = min(heights[i], heights[j]);
        while (i > 0 || j < heights.size()-1) {
            int nWidth = j - i + 1;
            int nMinIndex = min(heights[i],heights[j]);
            int nHeight = min(nMinHeight, nMinIndex);
            nMaxArea = max(nWidth*nHeight, nMaxArea);
            nMinHeight = nHeight;
            if (i > 0 && heights[i] > heights[j]) {
                i--;
            }
            if (j < heights.size()-1 && heights[j] > heights[i]){
                ++j;
            }
        }

        return nMaxArea;
    }
};

int main() {
    vector<int> heights{2,1,5,6,2,3};
    Solution a;
    cout << a.largestRectangleArea(heights) << endl;
    return 0;
}