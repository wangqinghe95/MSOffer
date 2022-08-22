#include<vector>
#include<unordered_set>
using namespace std;

/*
全排列：就是从0开始一直到nums.size()，每每交换两个数，待到遍历的当前index到数组结尾
        就可以push到指定的二维数组中去
如果是含有重复数字的一维数组中，那么如果是上述中交换的数前面已经做过交换了的话，这样就导致了有重复排列的数出现
本题就是这样，要解决的方案就是，当检测当前要交换的数组如果之前没有用过，那么就可以继续做交换
如果之前已经使用过了，那么就跳过
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums, 0, res);
        return res;
    }
private:
    void helper(vector<int>& nums, int index, vector<vector<int>>& res) {
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }

        unordered_set<int> nHashSet;
        for(int i = index; i < nums.size(); ++i) {
            if(nHashSet.count(nums[i]) == 0) {
                nHashSet.insert(nums[i]);
                swap(nums[i], nums[index]);
                helper(nums, index+1, res);
                swap(nums[i], nums[index]);
            }
        }

    }
};