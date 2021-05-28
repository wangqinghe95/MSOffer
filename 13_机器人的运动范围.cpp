#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//深度优先遍历
namespace DFS
{


class Solution {
public:
    int addXAndY(int x, int y){
        int result = 0;
        while (x > 0)
        {
            result += x % 10;
            x /= 10;
        }

        while (y > 0)
        {
            result += y % 10;
            y /= 10;
        }

        return result;      
    }
    void dfs(int x, int y, int k, vector<vector<int>> &res){
        if (x >= row || x < 0 || y >= col || y < 0 || res[x][y] == 1){
            return;
        }

        if (addXAndY(x,y) <= k){
            res[x][y] = 1;
            ans += 1;

            dfs(x+1, y, k, res);
            dfs(x-1, y, k, res);
            dfs(x, y+1, k, res);
            dfs(x, y-1, k, res);
        }

    }
    int movingCount(int m, int n, int k) {
        row = m;
        col = n;
        vector<vector<int>> res(m, vector<int>(n));

        //深度优先遍历
        dfs(0,0,k,res);
        return ans;
    }
private:
    int row;
    int col;
    int ans = 0;
};

}

namespace BFS
{
class Solution {
public:
    int addXAndY(int x, int y){
        int result = 0;
        while (x > 0)
        {
            result += x % 10;
            x /= 10;
        }

        while (y > 0)
        {
            result += y % 10;
            y /= 10;
        }

        return result;      
    }

    bool judge(int tx, int ty, int k)
    {
        if (tx >= row || tx < 0 || ty >= col || ty < 0 || addXAndY(tx,ty) > k)
        {
            return false;
        }
        return true;
    }

    int bfs(int i, int j, int k, vector<vector<int>> vis)
    {
        if (0 == k){
            return 1;
        }

        queue<pair<int,int>> Q;
        int dx[2] = {0,1};
        int dy[2] = {1,0};

        int ans = 1;

        Q.push(make_pair(0,0));
        while (!Q.empty())
        {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            for (int i = 0; i < 2; ++i){
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                if (judge(tx, ty, k) && vis[tx][ty] == 0){
                    Q.push(make_pair(tx,ty));
                    ans += 1;
                    vis[tx][ty] = 1;
                }
            }
        }
        return ans;
    }

    int movingCount(int m, int n, int k) {
        row = m;
        col = n;
        vector<vector<int>> vis(m, vector<int>(n, 0));  //标记某个结点是否被访问过
        
        return bfs(0,0,k, vis);
    }
private:
    int row;
    int col;
};
}


int main(){
    // DFS::Solution a;
    BFS::Solution b;
    cout << b.movingCount(16,8,4) << endl;
    return 0;
}