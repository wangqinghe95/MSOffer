#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        state = BEGIN;
        for (int i = 0; i < nums.size(); ++i) {
            switch(state)
            {
                case BEGIN:
                    state = SINGEL;
                    break;
                case SINGEL:
                    state = (nums[i] == nums[i-1] ? DOUBLE : ERROR);
                    break;
                case DOUBLE:
                    state = (i == nums.size()- 1 ? END : SINGEL);
                    break;
                case ERROR:
                    i--;
                    return nums[i-1];
                case END:
                    break;
                default:
                    break;
            }
        }
        
        return nums[nums.size() - 1];
    }
    int singleNonDuplicate_1(vector<int>& nums) {
        bool bSingle = true;
        for (int i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i-1] && bSingle == true) {
                bSingle = false;
            }
            else if (nums[i] != nums[i-1] && false == bSingle) {
                bSingle = true;
            }
            else if (nums[i] != nums[i-1] && bSingle == true) {
                return nums[i-1];
            }
        }
        return nums[nums.size()-1];
    }
private:
    enum State
    {
        BEGIN,
        SINGEL,
        DOUBLE,
        END,
        ERROR
    }state;
};

int main()
{
    Solution a;
    vector<int> nums{1,1,2,3,3,4,4,8,8};
    cout << a.singleNonDuplicate(nums) << endl;
    return 0;
}