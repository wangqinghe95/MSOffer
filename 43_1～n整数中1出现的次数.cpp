/*
解析：
*/


class Solution {
public:
    int countDigitOne(int n) {
        int temp = n;
        int x = temp % 10;
        int high = temp / 10;

        long digit = 1;
        int low = 0;

        int res = 0;
        while (high != 0 || x != 0) {
            if (0 == x) {
                res += high * digit;
            }
            else if (1 == x) {
                res += high * digit + low + 1;
            }
            else {
                res += (high + 1) * digit;
            }
            
            low = low + x * digit;
            x = high % 10;
            high /= 10;
            digit *= 10;
        }

        return res;
    }
};