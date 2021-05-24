#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//map
int findRepeatNumber(vector<int>& nums) {
    unordered_map<int, bool> mp;
    for (int i = 0 ; i < nums.size(); ++ i){
        if (mp[nums[i]] == false){
            mp[nums[i]] = true;
        }
        else{
            return nums[i];
        }
    }
    return -1;
}

//原地交换
int findRepeatNumber_1(vector<int>& nums)
{
    for (int i = 0; i < nums.size(); ++i){
        if (nums[i] == i){
            continue;
        }
        if (nums[i] == nums[nums[i]]){
            return nums[i];
        }
        swap(nums[i], nums[nums[i]]);
    }
    return -1;
}

int main(){
    vector<int> nums{2, 3, 1, 0, 2, 5, 3};
    int repeatNum = findRepeatNumber_1(nums);
    cout << "repeatNum = " << repeatNum << endl;
    return 0;
}