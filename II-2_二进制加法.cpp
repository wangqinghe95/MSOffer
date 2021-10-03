#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
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