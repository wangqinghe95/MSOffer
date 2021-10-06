#include<iostream>
#include<algorithm>
using namespace std;

// method of subduction to simulate division
class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.size() - 1;
        int len2 = b.size() - 1;

        string res;
        int carry = 0;
        while (len1 >= 0 || len2 >= 0) {
            int num1 = len1 >= 0 ? a[len1] - '0' : 0;
            int num2 = len2 >= 0 ? b[len2] - '0' : 0;
            int sum = num2 + num1 + carry;
            carry = sum / 2;
            res.push_back((sum % 2 + '0')); 
            len1--;
            len2--;
        }

        if (carry != 0) {
            res.push_back(carry  + '0');
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution_1 {
public:
    string addBinary(string a, string b) {
        int lenA = a.length()-1;
        int lenB = b.length()-1;
        string res = "";
        int carry = 0;
        while (lenA >= 0 && lenB >= 0)
        {
            int tmp = carry + (a[lenA]-'0') + (b[lenB]-'0');
            int cur = tmp % 2;
            carry = tmp / 2; 
            res.push_back(cur+'0');

            lenA--;
            lenB--;
        }

        while (lenA >= 0)
        {
            if (carry != 0)
            {
                res.push_back(a[lenA]+carry);
                carry /= 2;
            }
            else {
                res.push_back(a[lenA]);
            }
        }
        while (lenB >= 0)
        {
           if (carry != 0) {
               res.push_back(b[lenB]+carry);
               carry /= 2;
           }
           else {
               res.push_back(b[lenB]);
           }
        }
        
        return  reverse(res.begin(), res.end());
    }
};

int main() {

}