/*
选择数组的最小值，肯定是大于等于左侧的值，小于等于右侧的值
所以就是在最小值一定是在一个
*/

#include<iostream>
#include<vector>
using namespace std;


int minArray(vector<int>& numbers) {
    int left = 0;
    int right = numbers.size() - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        
        if (numbers[mid] < numbers[right]){
            right = mid;
        }
        else if (numbers[mid] > numbers[right]){
            left = mid + 1;
        }
        else{
            right -= 1;
        }
    }    

    return numbers[left];
}

int main(){
    // vector<int> nums{3,4,5,1,2};
    // vector<int> nums{2,2,2,0,1};
    vector<int> nums{3,1,1};
    cout << minArray(nums) << endl;
    return 0;
}