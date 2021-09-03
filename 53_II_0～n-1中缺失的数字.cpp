/*
二分法查找 0~n-1 中缺失的数
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == mid) {
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
hash:
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> hash(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            hash[nums[i]] = 1;
        }

        int result = 0;
        for (int i = 0; i < nums.size()+1; ++i) {
            if(hash[i] == 0) {
                result = i;
                break;
            }
        }

        return result;
    }
};

/*
数学算法：
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum_idea = n * (n+1) / 2;
        for (int i = 0; i < nums.size(); ++i) {
            sum_idea -= nums[i];
        }

        return sum_idea;
    }
};