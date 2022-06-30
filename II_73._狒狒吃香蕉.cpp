#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for (auto& pile : piles) {
            high = pile > high ? pile : high;
        }

        int return_speed = high;
        while (low < high) {
            int speed = (high - low) / 2 + low;
            long cost_time = getTime(piles, speed);
            if (cost_time <= h) {
                return_speed = speed;
                high = speed;
            }
            else {
                low = speed + 1;
            }
        }
        return return_speed;
    }
private:
    long getTime(vector<int>&piles, int speed) {
        long time = 0;
        for (int& pile : piles) {
            int cur_time = (pile + speed - 1) / speed;
            time += cur_time;
        }
        return time;
    }
};

int main()
{
    vector<int> piles{3,6,7,11};
    int h = 8;
    Solution a;
    cout << a.minEatingSpeed(piles, h) << endl;
    return 0;
}
