/*
快速幂
求 2^11 结果，如果是按照正常求值。则需要循环 11 次累积
求时间复杂度是 O(n)
快速幂求值的意思是，如果是 11，则可以将 11 分解为 1101
则 2^11 = 2^(1*2^0+0*2^1+1*2^3+1*2^4) = 2^2^0*2^2^2*2^2^3*2^2^4
*/

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0){
            return 0;
        }

        double res = 1;
        long b = n; //can't be int
        if (b < 0){
            x = 1/x;
            b = -b;
        }
        //5=101
        while (b > 0){
            if (b & 1 == 1){
                res *= x;
            }
            x*=x;
            b >>= 1;
        }

        return res;
    }
};