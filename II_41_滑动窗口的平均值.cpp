#include<iostream>
#include<deque>
#include<queue>
using namespace std;
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        maxSize = size;
        total = 0;
    }
    
    double next(int val) {
        total += val;
        if (maxSize == q.size()) {
            total -= q.front();
            q.pop();
        }
        q.push(val);
        return (double)total / (double)q.size();
    }
private:
    queue<int> q;
    int maxSize;
    int total;
};


// 使用队列即可，不用双向队列
class MovingAverage_1 {
public:
    /** Initialize your data structure here. */
    MovingAverage_1(int size) {
        maxSize = size;
        curSize = 0;
        curTotal = 0;
    }
    
    double next(int val) {
        if (dq.size() > maxSize) {
            curTotal -= dq.front();
            dq.pop_front();
        }
        dq.push_back(val);
        curTotal += val;
        return (double)curTotal / (double)(dq.size());
    }
private:
    deque<int> dq;
    int maxSize;
    int curSize;
    int curTotal;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */