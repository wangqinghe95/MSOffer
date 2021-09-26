#include<iostream>
#include<algorithm>
using namespace std;

// 本质：用减法代替除法

class Solution_1 {
public:
    int divide(int a, int b) {

        if (a == INT32_MIN && b == -1) {
            return INT32_MAX;
        }

        // a,b 同号 sign 为 1，反之为负号
        int sign = (a > 0) ^ (b > 0) ? -1 : 1; // a > 0 ^ b > 0 = 0 | a < 0 ^ b < 0 = 0

        if (a > 0) {
            a = -a;
        }
        if (b > 0) {
            b = -b;
        }

        unsigned int res = 0;
        while (a <= b)
        {
            int value = b;
            unsigned int k = 1;
            while (value >= 0xc0000000 && a <= value + value) {
                k += k;
                value += value;
            } 

            a -= value;
            res += k;
        }
                
        return sign == 1 ? res : -res;
    }
};

class Solution {
public:
    int divide(int a, int b) {
        if (a == INT32_MIN && b == -1) {
            return INT32_MAX;
        }

        // 时间复杂度有点高，怎么写个abs的数
        // auto abs = [](int a) { if (a < 0) { return -a;} else { return a;}};

        int sign = (a>0) ^ (b>0) ? -1 : 1;

        unsigned int ua = abs(a);
        unsigned int ub = abs(b);
        unsigned int res = 0;

        for (int i = 31; i >= 0; i--) {
            if ((ua >> i) >= ub) {
                ua = ua - (ub << i);
                res += 1 << i;
            }
        }
        return sign == 1 ? res : -res;
    }
};

int main() {
    Solution a;
    cout << a.divide(-2147483648,1) << endl;
    return 0;
}