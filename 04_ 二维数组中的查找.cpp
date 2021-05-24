/*
思路：二维数组从左向右递增，从上向下递增
      所以在二维数组的右上角上中位数
      判断数组当前数字和目标数相比较
      如果是当前数大说明目标只能在数组的左下角方向找
      反之只能在数组的右下角找
*/

#include<iostream>
#include<vector>
using namespace std;

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int columns = matrix[0].size();

    int row = 0;
    int col = columns - 1;
    while (row < rows && col >= 0)
    {
        if (matrix[row][col] == target){
            return true;
        }
        else if (matrix[row][col] > target){
            col--;
        }
        else{
            row++;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> nums{   {1,   4,  7, 11, 15},
                                {2,   5,  8, 12, 19},
                                {3,   6,  9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30},
                            };
    cout << findNumberIn2DArray(nums, 6) << endl;
    return 0;
}