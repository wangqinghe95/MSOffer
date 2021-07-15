/*
 * 模拟快排算法的思路
 */

#include<iostream>
#include<vector>
using namespace std;

namespace offer_21{
class Solution {
public:
    bool isOdd(int n) {
        if (n % 2 == 0) {
            return false;
        }
        else {
            return true;
        }
    }
    vector<int> exchange(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            while (left < right && isOdd(nums[left]))   // 判断奇偶性可以用 &1
            {
                left++;
            }
            while (left < right && !isOdd(nums[right]))
            {
                right--;
            }
            swap(nums[left], nums[right]);         
        }
        return nums;       
    }
};    
}

int main(){
    offer_21::Solution a;
    vector<int> tmp = {1,2,3,4};
    a.exchange(tmp);
    return 0;
}
