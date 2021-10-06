#include<iostream>
#include<vector>
using namespace std;

/*
遍历一遍n，用位运算求出每个数字的二进制的1的个数
*/

class Solution_1{
    public:
    vector<int> countBits(int n) {
        vector<int> res(n, 0);
        for (int i = 1; i < n; ++i ) {
            res[i] = getOne(i);
        }
        return res;
    }
    private:
    int getOne(int n){
        int count = 0;
        unsigned int tmp = n;
        while (tmp > 0)
        {
            if (tmp & 1) {
                count++;
            }
            tmp >>= 1;
            // cout << tmp << endl;
        }
        return count; 
    }
};

/*
二进制的数，加1，如果当前最后一位为0，加1，1的个数就多一个
如果最后一位为1，那么1的个数就是第 i/2 个数字的1的个数
i   0   1   2   3   4   5   6   7   8

res 0   1   1   2   1   2   2
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        res.push_back(0);
        for (int i = 1; i <= n; ++i) {
            if (i & 1) {
                res.push_back(res[i-1] + 1);
            }
            else {
                res.push_back(res[i/2]);
            }
        }

        return res;
    }
};

int main () {
    Solution a;
    a.getNumberOfOne(2);
    return 0;
}