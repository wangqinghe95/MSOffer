#include<iostream>
#include<vector>
using namespace std;

/*
递归
*/
int fabFunc(int n, vector<int>& dp){
    if (n <= 1){
        return n;
    }
    if (-1 == dp[n]){
        dp[n] = (fabFunc(n-1, dp) + fabFunc(n-2, dp))%1000000007;
    }

    return dp[n];
}

int fib_recursion(int n)
{
    vector<int> dp(n+1, -1);
    return fabFunc(n, dp);
}

/*
迭代
*/
int fib_iterator(int n)
{
    vector<int> dp;
    for (int i = 0; i <= n; ++i){
        if (0 == i){
            dp.push_back(0);
        }
        else if (1 == i){
            dp.push_back(1);
        }
        else{
            dp.push_back((dp[i-1]+dp[i-2]) % 1000000007);
        }
    }

    return dp[n];
}

int main()
{
    cout << fib_recursion(5) << endl;
    return 0;
}