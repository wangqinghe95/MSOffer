#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        heapSort(nums,k);
        return nums[0];
    }
private:
    void heapSort(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) {
            return;
        }
        for (int i = (n-2)/2; i >= 0; --i) {
            percdown(nums, n, i);
        }

        // n-k 表示找到第k大的元素，进行了k-1次的交换
        for (int i = n-1; i > n-k; i--){
            cout << endl;
            int tmp = nums[0];
            nums[0] = nums[i];
            nums[i] = tmp;
            percdown(nums, i, 0);
        }
    }

    void percdown(vector<int>& nums, int n, int parent) {
        int tmp = nums[parent];
        int child;
        for (; parent * 2 + 1 < n; parent = child){
            child = parent * 2 + 1;
            if (child + 1 < n && nums[child+1] > nums[child]) {
                child += 1;
            }

            if (nums[child] > tmp) {
                nums[parent] = nums[child];
            }
            else {
                break;
            }
        }
        nums[parent] = tmp;
    }
};

class Solution_1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSort(nums, 0, nums.size() - 1, k-1);
        // for (int i = 0; i < nums.size(); ++i) {
        //     cout << nums[i] << " " << endl;
        // }
        // cout << nums[k-1] << " ";

        // return nums[k-1];
    }
private:
    int quickSort(vector<int>& nums, int low, int high, int k){
        if (low < high ){
            int pivotpos = partition(nums, low, high);
            // if (pivotpos == k-1) {
            //     return;
            // }
            // quickSort(nums, 0, pivotpos-1, k);
            // quickSort(nums, pivotpos+1, high, k);
            if (pivotpos == k) {
                return nums[k];
            }
            else if (pivotpos > k) {
                return quickSort(nums, pivotpos+1, high, k);
            }
            else {
                return quickSort(nums, low, pivotpos-1, k);
            }
        }

    }
    int partition(vector<int>& nums, int low, int high){
        int tmp = nums[low];
        while(low < high) {
            while(low < high && nums[high] <= tmp) {
                high--;
            }
            if (low < high) {
                nums[low++] = nums[high];
            }
            while(low < high && nums[low] >= tmp) {
                low++;
            }
            if (low < high) {
                nums[high--] = nums[low];
            }
        }
        nums[low] = tmp;
        return low;
    }
};

int main()
{
    Solution a;
    vector<int> nums{3,2,1,6,5,4};
    int k = 2;
    cout << a.findKthLargest(nums,k) << endl;

    return 0;
}