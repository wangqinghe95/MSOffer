#include<iostream>
using namespace std;

class Solution {
public:
    void getReverseWord(string& to, string from) {
        if (to.size() != 0) {
            to.push_back(' ');
        }
        for (int i = from.size()-1; i >= 0; i--) {
            to.push_back(from[i]);
        }
    }
    string reverseWords(string s) {
        string res;
        string word;
        for (int i = s.size()-1; i >= 0 ; --i) {
            if (s[i] == ' ') {
                if (word.size() != 0) {
                    getReverseWord(res, word);
                    word.clear();
                }
            }
            else {
                word.push_back(s[i]);
            }
        }

        if (word.size() != 0) {
            getReverseWord(res, word);
        }

        return res;
    }
};

int main() {
    Solution a;
    string s("  hello world!  ");
    cout << a.reverseWords(s) << endl;
    return 0;
}