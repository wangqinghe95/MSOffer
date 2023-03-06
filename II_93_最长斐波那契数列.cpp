/**
 * @file II_93_最长斐波那契数列.cpp
 * @author your name (you@domain.com)
 * @brief 在一个数组中找到斐波那契数列最长子序列
 * 
 * dp 动态数组做法：
 * 0. dp 数组的含义：
 *      + 含义是如果 arr[k] + arr[j] = arr[i] 其中 0 <= k <= j， 那么 dp[i][j] 表示经过 i 到 j 的子序列有 dp[i][j] 的长度
 * 1. 转移公式：
 *      + 如果 arr[k] + arr[j] = arr[i]， 那么 dp[i][j] = dp[j][k] + 1 (长度+1)
 *      + 否则，则 dp[i][j] = 2 (斐波那契数组最短长度为 3)
 * 2. 初始状态
 *      + dp 初始化都可以为 2.
 * 
 * @version 0.1
 * @date 2023-03-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size()));
        unordered_map<int,int> mp;

        for(int i = 0; i < arr.size(); ++i){
            mp[arr[i]] = i;
        }

        auto max = [](int a,int b){
            return a > b ? a : b;
        };

        int ret = 0;
        for(int i = 1; i < arr.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                int temp = arr[i] - arr[j];
                if(mp.count(temp) && mp[temp] < j) {
                    dp[i][j] = dp[j][mp[temp]] + 1;
                }
                else{
                    dp[i][j] = 2;
                }
                ret = max(ret, dp[i][j]);
            }
        }

        return ret > 2 ? ret : 0;
    }
};


int main()
{
    Solution CSolut;
    vector<int> arr{1,2,3,4,5,6,7,8};
    vector<int> arr1{1,3,7,11,12,14,18};
    cout << CSolut.lenLongestFibSubseq(arr1) << endl;
    return 0;
}