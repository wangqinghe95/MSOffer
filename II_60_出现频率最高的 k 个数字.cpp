#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

// 还有一种方法是再使用一个有序的map，将出现的频率转换成map key，而数当作 value

// 对 map 的value 进行排序的方法
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (auto &x : nums) {
            if (mp.count(x)) {
                mp[x]++;
            }
            else {
                mp[x] = 1;
            }
        }

        vector<pair<int,int>> vtMap;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vtMap.push_back(make_pair(it->first,it->second));
        }


        sort(vtMap.begin(), vtMap.end(),
            [](const pair<int,int> &x, const pair<int,int>&y)->int{
                return x.second > y.second;
            });
        
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(vtMap[i].first);
        }

        return res;
    }
};