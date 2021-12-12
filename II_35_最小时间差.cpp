#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        const int MAX_NUMBER = 24*60 + 1;
        vector<bool> bVisited(MAX_NUMBER, false);
        int minMinute = MAX_NUMBER;
        int maxMinute = -1;
        for (auto & time : timePoints) {
            int curTime = getMinute(time);
            minMinute = curTime > minMinute ? minMinute : curTime;
            maxMinute = curTime > maxMinute ? curTime : maxMinute;
            if (bVisited[curTime] == true) {
                return 0;
            }
            else {
                bVisited[curTime] = true;
            }
        }

        int minDifference = minMinute + MAX_NUMBER - 1 - maxMinute;
        int pre = minMinute;
        for (int i = minMinute + 1; i <= maxMinute; ++i) {
            if (true == bVisited[i]) {
                minDifference = minDifference < (i-pre) ? minDifference : (i-pre);
                pre = i;
            }
        }

        return minDifference;
    }
private:
    int getMinute(const string& time) {
        int hour = atoi(time.substr(0,2).c_str());
        int minute = atoi(time.substr(3,2).c_str());
        return hour*60 + minute;
    }
};
/*
    先将字符串的时间转换成int型的分钟时间，再排序，在比较差值
    好处是简单，坏处是时间复杂度较高
*/


class Solution_2{
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minuteTime;
        for (int i = 0; i < timePoints.size(); ++i) {
            int tmpTime = getTimeMin(timePoints[i]);
            minuteTime.push_back(tmpTime);
        }
        sort(minuteTime.begin(), minuteTime.end());
        int min_diff = minuteTime[0] + 24 * 60 - minuteTime[minuteTime.size() - 1];
        for (int i = 1; i < minuteTime.size(); ++i) {
            int tmp_diff = minuteTime[i] - minuteTime[i-1];
            if (tmp_diff < min_diff) {
               min_diff = tmp_diff; 
            }
        }

        return min_diff;
    }
    int getTimeMin(const string& time) {
       int hour = (time[0]-'0') * 10 + (time[1] - '0');
       int min = (time[3] - '0') * 10 + (time[4] - '0');
       return hour * 60 + min;
    }
};

int main() {
    Solution a;
    vector<string> timePoints{"00:00","23:59","00:00"};
    cout << a.findMinDifference(timePoints) << endl;

}