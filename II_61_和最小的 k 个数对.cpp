#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

// 使用C++内置的堆，构建一个最大堆
// 找最小的前K个组合，堆排序的规则是K个大堆排序
// nums1的前k个数和nums2的前k个数组合，
// 当堆的数量小于K时直接加入，大于K时，如果当前的组合小于堆顶的元素组合之和
// 那么堆顶元素出栈，放入当前组合
class Solution_1 {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&](const pair<int,int> &lhs, const pair<int,int>& rhs){
            return lhs.first + lhs.second < rhs.first + rhs.second;
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> heap(cmp);
        for (int i = 0; i < nums1.size() && i < k; ++i){
            for (int j = 0; j < nums2.size() && j < k; ++j){
                if (heap.size() < k) {
                    heap.push({nums1[i], nums2[j]});
                }
                else if(nums1[i] + nums2[j] < heap.top().first + heap.top().second){
                    heap.pop();
                    heap.push({nums1[i], nums2[j]});
                }
            }
        }
        
        int size = heap.size();
        vector<vector<int>> res(size, vector<int>(2,0));
        for(int i = 0; i < size; ++i){
            res[size-i-1][0] = heap.top().first;
            res[size-i-1][1] = heap.top().second;
            heap.pop();
        }

        return res;
    }
};


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&](const pair<int,int> &lhs, const pair<int,int>& rhs) {
            return nums1[lhs.first] + nums2[lhs.second] > nums1[rhs.first] + nums2[rhs.second];
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> heap(cmp);
        for (int i = 0; i < k && i < nums1.size(); ++i){
            heap.push({i,0});
        }

        vector<vector<int>> res;
        while (k-- > 0 && !heap.empty()){
            auto ids = heap.top();
            heap.pop();

            res.push_back({nums1[ids.first], nums2[ids.second]});

            if (ids.second < nums2.size() - 1){
                heap.push({ids.first, ids.second+1});
            }
        }

        return res;
    }
};