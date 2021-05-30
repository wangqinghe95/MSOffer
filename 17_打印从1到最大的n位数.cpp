/*
这道题没有涉及到大数所以暴力破解都可以过
*/

class Solution {
public:
    vector<int> printNumbers(int n) {
        int cnt = 1;
        for (int i = 0; i < n; ++i){
            cnt *= 10;
        }

        vector<int> res;
        for (int i = 1; i < cnt; ++i){
            res.push_back(i);
        }

        return res;
    }
};

// 但是如果涉及到了大数，就需要去考虑了超出int的情况
// 此时需要对大数做计算处理
// dfs + 全排列

class Solution {
public:
    void dfs(int index, int n, vector<int>&res, string &path){
        if (n == index){
            int num = stoi(path);
            if (num != 0)
            {
                res.push_back(num);
            }
            return;
        }

        for (int i = 0; i < 10; i++){
            path[index] = i + '0';
            dfs(index+1, n, res, path);
        }
    }
    vector<int> printNumbers(int n) {
        vector<int> res;
        string path(n, '0');
        dfs(0, n, res, path);
        return res;
    }
};