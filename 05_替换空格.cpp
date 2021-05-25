/*
该问题的关键点在于一个空格置换三个字符的数组长度变化
*/

// 方法1：直接使用 string 来处理
class Solution {
public:
    string replaceSpace(string s) {
        string tmp;
        for (int i = 0; i < s.length(); ++i){
            if (s[i] == ' '){
                tmp += "%20";
            }
            else{
                tmp += s[i];
            }
        }
        return tmp;
    }
};

//方法2：对于char* 需要手动来控制空格和三个字符的置换
#include<iostream>
using namespace std;

string replaceSpace(string s)
{
    int len = s.length();
    char* tmp = new char[len * 3 + 1];
    int size = 0;
    for(int i = 0; i < len; ++i){
        if (s[i] == ' '){
            tmp[size++] = '%';
            tmp[size++] = '2';
            tmp[size++] = '0';
        }
        else{
            tmp[size++] = s[i];
        }
    }

    tmp[size] = '\0';
    return tmp;
}

int main(){
    string s("We are happy.");
    cout << replaceSpace(s) << endl;
    return 0;
}