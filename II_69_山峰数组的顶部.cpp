#include<iostream>
#include<vector>
using namespace std;

// 如果是是 left = mid - 1 方式切换 left 和 right 的值
// 那么就需要对 left = 1 ,right = n -2 的方式赋初始值
// 而这种赋值的方式只适合本体，即不需要对第一个数和最后一个数进行判断处理
// 如果使用的是 left = 0， right = n - 1 的方式赋初始值
// 那么 left = mid，right = mid 这种方式修改端点值

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1;
        int right = arr.size() - 2;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
                return mid;
            }
            else if (arr[mid] < arr[mid+1]) {
            // else if (arr[mid] > arr[mid+1]) {
                // right = mid - 1;
                left = mid + 1;
            }
            else {
                // left = mid + 1;
                right = mid -1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums{3,5,3,2,0};
    Solution a;
    a.peakIndexInMountainArray(nums);
    return 0;
}