#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
        int index = 0;
        int str_len = str.length();
        while (index < str_len && str[index] == ' ')
        {
            index++;
        }

        int flag = str[index] == '-' ? -1 : 1;
        if (str[index] == '+' || str[index] == '-') {
            index++;
        }

        int num = 0;
        int boundary = 214748364;   //大数处理
        while (str[index] >= '0' && str[index] <= '9') {
            int cur = str[index] - '0';
            if (num > boundary || (num == boundary && cur > 7)) {
                return flag == 1 ? INT_MAX : INT_MIN;
            }

            num = num * 10 + cur;
            index++;
        }

        return num*flag;        
    }
};

int main () {
    Solution a;
    string str = "42";
    cout << a.strToInt(str) << endl;
    return 0;
}