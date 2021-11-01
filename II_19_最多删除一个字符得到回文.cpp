#include<iostream>
using namespace std;

/*
当遇到
*/

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        for (; i < s.size(); ++i) {
            if (s[i] != s[s.size() - 1 - i]) {
                break;
            }
        }

        return i == s.size() ? true : isPalindrome(s, i, s.size() - 2 - i)
                    || isPalindrome(s, i+1, s.size() - i - 1);
    }
private:
    bool isPalindrome(string& s, int i, int j) {
        while(i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};

int main() {
    string s("abca");
    Solution a;
    cout << a.validPalindrome(s) << endl;
    return 0;
}