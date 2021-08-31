#include<vector>
#include<iostream>
using namespace std;


/*
dp思路：
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int a = 0;
        int b = 0;
        int c = 0;
        auto f = [](int x , int y) {
            return x < y ? x : y;
        };
        for (int i = 1; i < n; ++i) {
            int n1 = dp[a] * 2;
            int n2 = dp[b] * 3;
            int n3 = dp[c] * 5;
            dp[i] = f(f(n1,n2),n3);
            if(n1 == dp[i]){
                a++;   
            }
            if (n2 == dp[i] ) {
                b++;
            }
            if (n3 == dp[i]) {
                c++;
            }
        }

        return dp[n-1];
    }
};

int main() {
    Solution a;
    cout << a.nthUglyNumber(10) << endl;;
    return 0;
}