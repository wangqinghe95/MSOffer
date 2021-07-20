#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> two_vecotr;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        // if (row == 0){
        //     return {};
        // }
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

int main() {
    two_vecotr matrix{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    Solution a;
    vector<int> res = a.spiralOrder(matrix);
    return 0;
}