#include<iostream>
#include<string>
#include<vector>
using namespace std;


/*
dp思路：
    本质来说，再第i个字符出，可能有两个翻译方式，一个是翻译 xi，一个是翻译 x[i-1]x[i]
    这两种方式中，翻译 x[i] 就是 dp[i-1] 种方式，翻译 x[i-1][i] 就是 dp[i-2] 种方式 

    边界值就是 dp[0] 和 dp[1] 两个值
    dp[1] = 1 这个是没得说的
    dp[2] = dp[1] + dp[0]
    如果 nums[1] 和 nums[2] 组合的数小于 25，即类似于 12，那就有两种，但是如果是 26，就只有一种
    所有 dp[0] = 1
*/
class Solution_dp {
public:
    int translateNum(int num) {
        string str = to_string(num);
        int len = str.size();
        vector<int> dp(len+1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= len; ++i) {
            int tmp = (str[i-2] - '0' ) * 10 + (str[i-1] - '0');
            if (tmp >= 10 && tmp < 26) {
                dp[i] = dp[i-1] + dp[i-2];
            }
            else {
                dp[i] = dp[i-1];
            }
        }

        return dp[len];
    }
};

/*
递归思路：
*/
class Solution {
public:
    int backTrace(string& str, int index) {
        if (index == str.size()) {
            return 1;
        }
        if (index == str.size() - 1 || str[index] == '0' || str.substr(index, 2) > "25") {
            return backTrace(str, index + 1);
        }
        return backTrace(str, index+1) + backTrace(str, index+2);
    }
    int translateNum(int num) {
        string str = to_string(num);
        return backTrace(str, 0);
    }
};

int main() {
    Solution a;
    cout << a.translateNum(12258) << endl;
    return 0;
}