/*
滑动窗口
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int left = 1;
        int right = 1;
        int sum = 0;

        while (left <= target / 2) {
            if (sum < target) {
                sum += right;
                right++;
            }
            else if (sum > target){
                sum -= left;
                left++;
            }
            else {
                res.push_back(vector<int>{});
                for (int i = left; i < right; ++i) {
                    res[res.size()-1].push_back(i);
                }

                sum -= left;
                left++;
            }
        }

        return res;
    }
};

int main() {
    Solution a;
    vector<vector<int>> res = a.findContinuousSequence(9);
    return 0;
}