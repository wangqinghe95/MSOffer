#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k || k < 0) {
            return {};
        }

        deque<int> dq;
        vector<int> res;
        int left = 1-k;
        int right = 0;
        while (right < n) {
            // left start by 1 because 
            if (left >= 1 && nums[left-1] == dq[0]) {
                dq.pop_front();
            }

            while (!dq.empty() && dq[0] < nums[right])
            {
                dq.pop_front();
            }

            while (!dq.empty() && dq[dq.size()-1] < nums[right]) {
                dq.pop_back();
            }

            dq.push_back(nums[right]);
            if (left >= 0) {
                res.push_back(dq[0]);
            }

            left++;
            right++;            
        }
        return res;
    }
};

int main() {
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    Solution a;
    a.maxSlidingWindow(nums, 3);
    return 0;
}