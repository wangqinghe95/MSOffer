/*
这道题本质是一个子串和主传的匹配，但是多了 * 和 . 的匹配
. 号是匹配下一个任意的字符
* 号表示前一个字符的任意个数，可以为 0
*/

/*
方法一：使用dp数组的思路，对字符进行逐步匹配。
s[i] 表示字符串 s 的第 i 个元素，p[j] 表示字符串 p 的第 j 个元素
dp[i][j] 表示 字符串 s 的前 i 个元素和字符串 p 前 j 个元素是否匹配

转移方程：
1. 如果没有 * 号和 . 号，那么 dp 的转移方程是：
    if(s[i]==s[j]) f[i][j] = f[i-1][j-1];
    else            f[i][j] = false;
2. 如果加上 . 号，那么 dp 数组的转移方程就可以变成
    if(s[i]==s[j] || s[j] == ".") f[i][j-1] = f[i-1][j];
    else            f[i][j] = false;
3. 如果加上 * 号，那么 dp 数组的转移方程式就变成了
    if(p[j-1] != "*")
        if(s[i]==p[j] || s[j] == ".") dp[i][j-1] = dp[i-1][j];    //1
        else            dp[i][j] = false;                        //2
    else if (p[j-1] == "*")
        dp = dp[i][j-2]
            | dp[i-1][j] & s[i-1] == p[j-2]
            | dp[i-1][j] & p[j-2] == "."
    解释：  1.p[j] != "*" 的情况就是 2 的情况；
           2.p[j] == "*" 时
            1）dp[i][j-2] 的意思是，p[j-1]是 "*", p[j-2] 是啥字符无所谓了，因为 "*" 可以为 0，此时 dp[i][j] 就等于 dp[i][j-2]
            2）dp[i-1][j] & s[i-1] == p[j-2] 的所以是，当 s 的前 i-1 个字符和 p 的前 j 个字符匹配，如果 s 的第 i 个字符和
                第 j-1 个字符匹配，因为 p 的第 j 个元素是 *,可以为1，此时只要 s 的第 i-1 个元素和 p 的 j-2 个元素相同，
                就能表示 dp[i][j] = 1
            3）p 的第 j-2 元素，是因为当 p[j-1] 是 * 时， 前一个元素可以不看，所以有了 dp[i][j] = dp[i][j-2]
            4）因为 dp[0][0] 表示两个空串的情况，所以 dp 的 i 和 s 的 i 以及 dp 的 j 和 p 的 j 都差了一个 1

4. 总上，可总结为：
当 p[j-1] == '*' 时：

dp[i][j] =  dp[i][j-2]                      //1
            dp[i-1][j] && s[i-1] == p[j-1]  //2
            dp[i-1][j] && p[j-1] == '.'     //3

当 p[j-1] != '*' 时：
dp[i][j] =  dp[i-1][j-1] && s[i-1] == p[j-1]     //4
            dp[i-1][j-1] && p[j-1] == '.'   //5

初始化：
1. dp[0][0] 表示两个空串的匹配
2. 对于 s 的空串匹配，当 p 的偶数位上都是 * 时，可以匹配上，因为 * 值全取 1 即可。

本思路的解释是根据 https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/jian-zhi-offer-19-zheng-ze-biao-da-shi-pi-pei-dong/         

*/

#include<iostream>
#include<vector>
using namespace std;

namespace Offer_19{
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size() + 1;
        int n = p.size() + 1;
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        dp[0][0] = true;
        for (int j = 2; j < n; j += 2){
            // if (p[j-1] == '*'){
            //     dp[0][j] = dp[0][j-2];
            // }
            dp[0][j] = dp[0][j-2] && p[j-1] == '*';
        }

        for (int i = 1; i < m; ++i){
            for (int j = 1; j < n; ++j){
                if (p[j-1] != '*'){
                    if (dp[i-1][j-1] == true && s[i-1] == p[j-1]){          //4
                        dp[i][j] = true;
                    }
                    else if (dp[i-1][j-1] == true && p[j-1] == '.'){    //5
                        dp[i][j] = true;
                    }
                }
                else{
                    if(dp[i][j-2]){
                        dp[i][j] = true;
                    }
                    else if (dp[i-1][j] && s[i-1] == p[j-2]){
                        dp[i][j] = true;
                    }
                    else if (dp[i-1][j] && p[j-2] == '.'){
                        dp[i][j] = true;
                    }
                }
            }
        }

        return dp[m-1][n-1];
    }
};    
}

int main(){
    Offer_19::Solution a;
    string s("aaa");
    string p("ab*.*");
    cout << a.isMatch(s,p) << endl;
    return 0;
}

/*
方法二：递归
*/

/*
方法三：NFA（不确定自动机）
*/