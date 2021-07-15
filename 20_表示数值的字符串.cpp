/*
* 方法二：确定有限状态自动机
* 有限状态机要根据字符类型和合法数值的特性，先定义状态，再划出状态转移图，最好写出代码
* 字符类型：
    空格： [] 
    数字： 0-9
    正负号： +，- 
    小数点：.
* 状态定义：
    0：开始的空格；
    1：幂符号前的正负号；
    2：小数点前的数字；
    3：小数点、小数点后的数字；
    4：当小数点前为空格时，小数点、小数点后的数字；
    5：幂符号；
    6：幂符号后的正负号；
    7：幂符号后的数字；
    8：结尾的空格；
*/


/*
状态图可参照
https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/solution/mian-shi-ti-20-biao-shi-shu-zhi-de-zi-fu-chuan-y-2/
*/

#include<iostream>
#include<unordered_map>
using namespace std;

namespace Offer_1{
class Solution {
public:
    bool isNumber(string s){
        unordered_map<char,int> mp[9];
        mp[0][' '] = 0; mp[0]['s'] = 1; mp[0]['d'] = 2; mp[0]['.'] = 4;
        mp[1]['d'] = 2; mp[1]['.'] = 4;
        mp[2]['.'] = 3; mp[2]['d'] = 2; mp[2]['e'] = 5; mp[2][' '] = 8;
        mp[3]['d'] = 3; mp[3]['e'] = 5; mp[3][' '] = 8;
        mp[4]['d'] = 3;
        mp[5]['s'] = 6; mp[5]['d'] = 7;
        mp[6]['d'] = 7;
        mp[7]['d'] = 7; mp[7][' '] = 8;
        mp[8][' '] = 8;
        int p = 0;
        char t;
        for (char c : s) {
            if ( c >= '0' && c <= '9'){
                t = 'd';
            }
            else if (c == '+' || c == '-') {
                t = 's';
            }
            else if (c == 'e' || c == 'E') {
                t = 'e';
            }
            else {
                 t = c;
            }

            if(mp[p].find(t) == mp[p].end()) {
                 return false;
            }
            else {
                p = mp[p][t]''
            }
        }

        if (p == 2 || p == 3 || p == 7 || p == 8) {
            return true;
        }
        return false;
    }
};
}


/*
处理字符串：判断字符串是否为数值格式
1.处理字符串的开头和结尾空白字符
2.找到e或E以及.的位置
3.判断.和e以及E后面的数是否是整数

s中，只能包含 +,-,.,e,E,和数字
其中
1. +，- 只能在 e 或 E 两侧
2. . 后只能是数字，且 . 只能有一个

方法错误，硬来不行滴～还是得上算法
*/

/* 
 * 硬来应该还是可以的，但是没写出来。这道题可以学习有限状态机   --by 20210713
 */

#include<iostream>
#include<vector>
using namespace std;

namespace Offer_20{
class Solution {
public:
    int getFirstChar(string& s, int &nBegin, int &nEnd){
        bool bBegin = false;
        bool bEnd = false;
        int len = s.length();
        for (int i = 0; i < len; ++i){
            if (s[i] != ' ' && !bBegin){
                nBegin = i;
                bBegin = true;
            }
            if (s[len - i - 1] == ' ' && !bEnd){
                nEnd = len-i;   //
                bEnd = true;
            }

            if (bEnd && bBegin){
                return 0;
            }
            if (nBegin >= nEnd){
                return -1;
            }
        }       
    }
    bool judgeChar(char c){
        if (c == ' ' || c == '+' || c == '-' || (c >= '0' && c <= '9')){
            return true;
        }
        else{
            return false;
        }
    }
    bool checkInteger(const string& s, int nBegin, int nEnd){
        bool bExistNumber = false;       
        
        for (int i = nBegin; i < nEnd; ++i){
            if (s[i] == '+' || s[i] == '-'){
                continue;
            }
            else if (s[i] >= '0' && s[i] <= '9'){
                bExistNumber = true;
            }
            else{
                return false;
            }            
        }
        return bExistNumber;
    }
    bool isNumber(string s) {
        int nPosFloat = -1;
        int nPosE = -1;
        int nPosLeft = -1;
        int nPosRight = -1;
        for (int i = 0; i < s.length(); ++i){
            if (s[i] == ' ' || (s[i] >= '0' && s[i] <= '9')){
                continue;
            }
            else if (s[i] == '.'){
                if (nPosFloat == -1){
                    nPosFloat = i;
                }
                else{
                    return false;
                }
            }
            else if (s[i] == '+' || s[i] == '-'){
                if (nPosE == -1 && nPosLeft == -1){
                    nPosLeft = i;
                }
                else if (nPosE != -1 && nPosRight == -1){
                    nPosRight = i;
                }
                else{
                    return false;
                }
            }
            else if (s[i] == 'E' || s[i] == 'e'){
                nPosE = i;
            }
            else{
                return false;   //如果出现其他字符
            }
        }

        /*
        * 1. 没有e，只能有一个 + 或者 -
        * 2. 有e，+,- 号必须在 e 的两侧
        */
        // if (nPosE == -1 && (nPosLeft != -1 && nPosRight != -1)){
        //     return false;
        // }
        // else if (nPosE != -1 && ((nPosLeft-nPosE)*(nPosRight-nPosE) < 0)){
        //     return false;
        // }
        int nBegin = 0;
        int nEnd = s.length();
        while (nBegin < nEnd)
        {
            if (s[nBegin] == ' ')
            {
                nBegin++;
            }
            else{
                break;
            }
        }

        while (nEnd > 0)
        {
            if (s[nEnd-1] == ' ')
            {
                nEnd--;
            }
            else{
                break;
            }
        }
              
        //如果 nPosE ！= -1 && nPosFloat ！= -1 ， . 在 e 前，检查 . 前， 
        if(nPosE != -1 && nPosFloat != -1){
            return (nPosE > nPosFloat) && checkInteger(s, nBegin, nPosFloat)
                                        && checkInteger(s, nPosFloat+1, nPosE)
                                        && checkInteger(s, nPosE+1, nEnd);
        }
        else if (nPosE != -1){  //只有e，后面需要是整数
            return checkInteger(s, nBegin, nPosE) && checkInteger(s, nPosE+1, nEnd);
        }
        else if (nPosFloat != -1){
             return checkInteger(s, nPosFloat+1, nEnd) || checkInteger(s, nBegin, nPosFloat);
        }
        else{
            return checkInteger(s, nBegin, nEnd);
        }
        
    }
};    
}

int main(){
    Offer_20::Solution a;

#if 0
    vector<string> s{"+100","5e2","-1"+100","5e2","-123", "3.14156", "-1E-16", "0123"23", "3.14156", "-1E-16", "0123"};
#else
    vector<string> s{"12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"};
#endif

#if 0
    for (int i = 0; i < s.size(); ++ i){
        cout << a.isNumber(s[i]) << endl;
    }
#else
    // cout << a.isNumber("-1E-16") << endl;
    // cout << a.isNumber("3.") << endl;
    // cout << a.isNumber("e") << endl;

    cout << a.isNumber(". 1") << endl;


#endif
    return 0;
}