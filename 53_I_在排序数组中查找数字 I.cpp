#include<iostream>
#include<vector>
using namespace std;

/*
二分法找到target左侧的right值（比target区域的下一位），然后target-1的下一位（target 的首位），
相减就是他们的区域范围
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary(nums,target) - binary(nums, target-1);
    }
private:
    int binary(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left+right) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return left;
    }
};

/*
二分法先找到目标值，然后往前往后遍历累加
*/
class Solution_1 {
public:
    int search(vector<int>& nums, int target) {
        int index = binary(nums, target);
        if (index == -1) {
            return 0;
        }

        int count = 1;
        int left = index-1;
        int right = index+1;
        while(left >= 0 && nums[left] == target) {
            left--;
            count++;
        }
        while(right < nums.size() && nums[right] == target) {
            right++;
            count++;
        }

        return count;
    }
private:
    int binary(vector<int> nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                return mid;
            }
        }

        return -1;
    }
};
int main (){
    Solution a;
    vector<int> nums{5,7,7,8,8,10};
    // vector<int> nums{1,3};
    cout << a.search(nums, 5) << endl;
}