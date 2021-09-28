#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int lenA = a.length();
        int lenB = b.length();

        int carry = 0;
        string res = "";
        while (lenA > 0 || lenB > 0) {
            int numA = lenA > 0 ? a[lenA] - '0' : 0;
            int numB = lenB > 0 ? b[lenB] - '0' : 0;

            lenB--;
            lenA--;

            int tmp = numB + numA + carry;
            carry = tmp / 2;
            res.push_back((tmp%2)+'0');
        }

        if (carry != 0) {
            res.push_back(carry + '0');
        }

        // return reverseString(res);
        reverse(res.begin(), res.end());
        return res;
    }
// private:
//     string reverseString(string& s) {
//         for (int i = 0; i < s.length()/2; ++i) {
//             s[i] = s[s.length() - i - 1];
//         }
//         return s;
//     }
};

int main() {
    Solution solution;
    string a("11");
    string b("10");
    cout << solution.addBinary(a, b) << endl;
}

/*

*/

string addStrings(string num1, string num2) {
    string res = "";

    int i1 = num1.length() - 1, i2 = num2.length() - 1;
    int carry = 0;
    while (i1 >= 0 || i2 >= 0) {
        int x = i1 >= 0 ? num1[i1] - '0' : 0;
        int y = i2 >= 0 ? num2[i2] - '0' : 0;

        int sum = x + y + carry;
        res.push_back('0' + sum % 2);
        carry = sum / 2;

        i1--;
        i2--;
    }
    if (carry != 0) res.push_back('0' + carry);
    reverse(res.begin(), res.end());
    return res;
}