/*
* quickSort
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums, 0, nums.size()-1);
        return nums[nums.size()-k];
    }
private:
    void quickSort(vector<int>& nums, int low, int high) {
        if(low < high) {
            int pivotpos = partition(nums, low, high);
            quickSort(nums, low, pivotpos-1);
            quickSort(nums, pivotpos+1, high);
        }
    }
    int partition(vector<int>&nums, int low, int high){
        int tmp = nums[low];
        while(low < high) {
            while(low < high && nums[high] >= tmp) {
                high--;
            }
            nums[low] = nums[high];
            while(low < high && nums[low] <= tmp){
                low++;
            }
            nums[high] = nums[low];
        }
        nums[low] = tmp;
        return low;
    }
};

/*
* quicksort select branch
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSort(nums, 0, nums.size()-1, nums.size()-k);
    }
private:
    int quickSort(vector<int>& nums, int low, int high, int index) {
            int pivotpos = partition(nums, low, high);
            if (index == pivotpos) {
                return nums[index];
            }
            else {
                return pivotpos > index ? quickSort(nums, low, pivotpos-1, index) : quickSort(nums, pivotpos+1, high, index);
            }

    }
    int partition(vector<int>&nums, int low, int high){
        int tmp = nums[low];
        while(low < high) {
            while(low < high && nums[high] >= tmp) {
                high--;
            }
            nums[low] = nums[high];
            while(low < high && nums[low] <= tmp){
                low++;
            }
            nums[high] = nums[low];
        }
        nums[low] = tmp;
        return low;
    }
};

/*
 * heap sort
*/