/*
dp思路：
    走过路径最大和，可以得出最后的右下角出口肯定是一路加最大值过来的
    按照这个思路模拟判断过程：
    dp[0][0] = grid[0][0]
    最上一行可得：dp[0][j] = dp[0][j-1] + grid[0][j]
    最左边一行：dp[i][0] = dp[i-1][0] + grid[i][j]
    其余行：dp[i][j] = max(dp[i-1][j],dp[i][j-1])+grid[i][j]
*/

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        auto f = [](int a, int b){return a > b ? a : b;};

        vector<vector<int>> dp(row, vector<int>(col));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (0 == i && 0 == j) {
                    dp[i][j] = grid[i][j];
                }
                else if (0 == i) {
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                }
                else if (0 == j) {
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                }
                else{
                    dp[i][j] = f(dp[i-1][j],dp[i][j-1]) + grid[i][j];
                }
            }
        }

        return dp[row-1][col-1];
    }
};

/*
DFS：算法步骤
*/

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> matrix(row, vector<int>(col));
        return DFS(grid, matrix, 0, 0);
    }

    int DFS(vector<vector<int>> &grid, vector<vector<int>> &matrix, int x, int y) {
        if (matrix[x][y] != 0) {
            return matrix[x][y];
        }

        if (x == grid.size() - 1 && y == grid[0].size() - 1) {
            matrix[x][y] = grid[x][y];
            return grid[x][y];
        }

        int right_value = 0;
        int left_value = 0;
        if (y < grid[0].size() - 1){
            right_value = DFS(grid, matrix, x, y+1) + grid[x][y];
        }

        if (x < grid.size() - 1) {
            left_value = DFS(grid,matrix, x+1, y) + grid[x][y];
        }

        matrix[x][y] = left_value > right_value ? left_value : right_value;
        return matrix[x][y];
    }
};