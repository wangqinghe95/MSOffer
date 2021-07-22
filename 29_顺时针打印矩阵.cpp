#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> two_vecotr;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        int row = matrix.size();
        int col = matrix[0].size();
        int total = row * col;
        vector<int> res = {};

        int L = 0, R = col-1, U = 0, B = row-1;
        int i = 0, j = 0;
        while (res.size() < total)
        {
            while (res.size() < total && j < R)
            {
                res.push_back(matrix[i][j]);
                j++;
            }
            while (res.size() < total && i < B) 
            {
                res.push_back(matrix[i][j]);
                i++;
            }
            while (res.size() < total && j > L)
            {
                res.push_back(matrix[i][j]);
                j--;
            }
            while (res.size() < total && i > U)
            {
                res.push_back(matrix[i][j]);
                i--;
            }
            R--;
            B--;
            L++;
            U++;
            i++;
            j++;

            if (total == res.size() + 1){
                res.push_back(matrix[i][j]);
            }
        }

        return res;
        
    }
};

namespace offer_29 {
class Solution {
private:
    int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if ( 0 == matrix.size() || 0 == matrix[0].size() ) {
            return {};
        }

        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols));
        int total = rows * cols;
        vector<int> order(total);

        int index_row = 0, index_col = 0;
        int index_direction = 0;
        for (int i = 0; i < total; ++i) {
            order[i] = matrix[index_row][index_col];
            visited[index_row][index_col] = true;
            int next_row = index_row + directions[index_direction][0];
            int next_col = index_col + directions[index_direction][1];
            if (next_row < 0 || next_row >= rows || next_col < 0 || next_col >= cols || visited[next_row][next_col] == true) {
                index_direction = (index_direction + 1) % 4;
            }

            index_row += directions[index_direction][0];
            index_col += directions[index_direction][1];
        }

        return order;
    }
};    
}

namespace offer_29_1 {
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if ( 0 == matrix.size() || 0 == matrix[0].size()) {
            return {};
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> order;
        int left = 0;
        int right = cols - 1;
        int top = 0;
        int bottom = rows - 1;

        while (left <= right && top <= bottom)
        {
            for (int column = left; column <= right; ++column) {
                order.push_back(matrix[top][column]);
            }

            for (int row = top + 1; row <= bottom; ++row ) {
                order.push_back(matrix[row][right]);
            }

            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    order.push_back(matrix[bottom][column]);
                }
                for (int row = bottom; row > top; --row) {
                    order.push_back(matrix[row][left]);
                }
            }

            left++;
            right--;
            top++;
            bottom--;
        }
        return order;
    }
};    
}

int main() {
    two_vecotr matrix{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int debug = 3;
#if (debug == 1)
    Solution a;
    vector<int> res = a.spiralOrder(matrix);
#elif (debug == 2)
    offer_29::Solution a;
    a.spiralOrder(matrix);
#else
    offer_29_1::Solution a;
    a.spiralOrder(matrix);
#endif
    return 0;
}