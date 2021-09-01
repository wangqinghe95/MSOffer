#include<iostream>
#include<vector>
using namespace std;

/*
归并算法：再归并算法的分治，然后合并的过程中，会有一个求逆序的时机
        1、在分治排序的过程中，当递归到left+1=right，即两个数排序的msort中，在排序的过程中，会将左右两部分进行比较
        2、如果是右侧大于左侧的情况出现，也就意味着有逆序对了
        3、具体的实现是，在左侧值往tmp有序数组中放的时候，此时右侧已经被放入的数都会跟当前放入的左侧的值构成逆序对，
        4、原因是：有序数组是从小往大排序，此时先进去的右侧数组在原本数组中是位于右半侧，又因为是新进去，意味着它要比后进去的数要小
        5、一旦左侧值后进去，它就和先进去的左侧值构成逆序对。有几个先进去的右侧值，此时进去的左侧值就和他们一一的构成几个逆序对
        6、具体的表现为 r-(mid+1) 这个值就是已经进去了几个右侧的值了
*/
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size(), 0);
        return merge(nums, tmp, 0, nums.size()-1); 
    }
private:
    int merge(vector<int>& nums, vector<int>& tmp, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            int result = merge(nums, tmp, left, mid) + merge(nums, tmp, mid+1, right);
            return msort(nums, tmp, left, mid, right, result);
        }
        else {
            return 0;
        }
    }
    int msort(vector<int>&nums, vector<int>& tmp, int left, int mid, int right, int &result) {
        int start = left;
        int l = left;
        int r = mid + 1;

        int rev_count = 0;
        while (l <= mid && r <= right)
        {
            if (nums[l] <= nums[r]) {
                tmp[start++] = nums[l++];
                result += (r - (mid + 1));
            }
            else {
                tmp[start++] = nums[r++];
            }            
        }
        while (l <= mid)
        {
            tmp[start++] = nums[l++];
            result += (r-(mid+1));
        }
        while (r <= right)
        {
            tmp[start++] = nums[r++];
        }
        
        for (; left <= right; left++) {
            nums[left] = tmp[left];
        }

        return result;
    }
};

int main() {
    vector<int> nums{7,5,6,4};
    Solution a;
    cout << a.reversePairs(nums) << endl;
    return 0;
}