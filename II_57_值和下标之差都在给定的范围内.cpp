#include<iostream>
#include<set>
#include<vector>
using namespace std;

//题目要求的是求一个数的前后k个数中是否存在一个数与自己的差值在k以内
// 方法一就是，遍历整个数组，然后先找到当前数上下差t的数的范围
// 也就是 [nums[i]-t,nums[i]+t]，然后在set集合中找是否有一个数比这个区域的下限大
// 如果在set集合中找到一个数比下限大，并且这个数还小于上线，就表示找到了这个数，可以直接返回true
// 如果没有找到符合条件的数，那么就把当前的这个数插入到set集合中
// 如果当前访问的index 大于等于k时，那么就把nums[i-k]从set集合中去掉
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> st;
        for (int i = 0; i < nums.size(); ++i) {
            int lower = max(nums[i], INT_MIN+t) - t;
            int upper = min(nums[i], INT_MAX-t) + t;
            auto it = st.lower_bound(lower);
            if (it != st.end() && *it <= upper) {
                return true;
            }
            st.insert(nums[i]);
            if (i >= k) {
                st.erase(nums[i-k]);
            }
        }
        return false;
    }
};

// 桶排序，以后再研究