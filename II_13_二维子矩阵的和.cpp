#include<iostream>
#include<vector>
using namespace std;

/*
二维数组前缀和：查找O(1)
*/
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m > 0) {
            int n = matrix[0].size();
            sums.resize(m+1, vector<int> (n+1));
            for (int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    sums[i+1][j+1] = sums[i+1][j] + sums[i][j+1] - sums[i][j] + matrix[i][j]; 
                }
            }
        }
    }
    
    /*
        四个角：
        [row2+1][col2+1](右下角)
        [row2+1][col1](左下角)
        [row1][col2+1](右上角)
        [row1][col1](左上角)
        右下角的值 sums[row2+1][col2+1] 是 martix 中从 0~row2， 0~col2 这块区域和
        现在只想要 matrix[row1][col1]-matrix[row2][col2] 区域的数字和
        那么就 sum(matrix[row2][col2+1] - matrix[row1][col1])
        sum二位数组中存储的就是和了，直接减去 sum[row2+1][col] 和 sum[row1][col2+1]
        然后再加上多减去的一块区域 sums[row1][col1] 就是所求
    */
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
    }
    
private:
    vector<vector<int>> sums;
};

/*
一维数组前缀和：时间检索的复杂度是 O(m)
*/
class NumMatrix_2 {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m > 0) {
            int n = matrix[0].size();
            sum.resize(m, vector<int>(n+1));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    sum[i][j+1] = matrix[i][j] + sum[i][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for (int i = row1; i <= row2; ++i) {
            res += (sum[i][col2+1]-sum[i][col1]);
        }
        return res;
    }
private:
    vector<vector<int>> sum;
};

/*
时间复杂度超了
*/
class NumMatrix_1 {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m_matrix.reserve(matrix.size());
        for (int i = 0; i < matrix.size(); ++i) {
            m_matrix.push_back(vector<int>(matrix[i].size()));
            for (int j = 0; j < matrix[i].size(); ++j) {
                m_matrix[i][j] = matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int j = col1; j <= col2; ++j) {
            for (int i = row1; i <= row2; ++i) {
                sum += m_matrix[i][j];
            }
        }
        return sum;
    }
private:
    vector<vector<int>> m_matrix;
};

int main() {
    vector<vector<int>> matrix{{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
    NumMatrix *obj = new NumMatrix(matrix);
    cout << obj->sumRegion(1,2,2,4) << endl;
    return 0;
}