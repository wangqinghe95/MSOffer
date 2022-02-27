#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
// 堆排序
// 未验证，后面刷题时再验证
// 赋值可以使用std::move
class Solution {
public:
    struct Record{
        int cnt;
        int val;
        Record(){};
        Record(int _cnt, int _val) : cnt(_cnt), val(_val){}
        bool operator< (const Record& a) const {
            return cnt < a.cnt;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.count(nums[i])) {
                mp[nums[i]]++;
            }
            else {
                mp[nums[i]] = 0;
            }
        }
        
        vector<Record> rec;
        auto iter = mp.begin();
        for ( ;iter != mp.end() && rec.size() < k; ++iter) {
            Record tmp;
            tmp.cnt = iter->second;
            tmp.val = iter->first; 
            rec.push_back(tmp);
        }

        for (int i = (k-2)/2; i >= 0; --i){
            upAdjust(rec, k, i);
        }

        for (; iter != mp.end(); ++iter){
            if (iter->second > rec[0].cnt){
                rec[0] = rec[k-1];
                Record tmp;
                tmp.val = iter->first;
                tmp.cnt = iter->second;
                rec[k-1] = tmp;

                upAdjust(rec, k, (k-2)/2);
            }
        }

        vector<int> res;
        for (int i = 0; i < rec.size(); ++i) {
            res.push_back(rec[i].val);
        }

        return res;
    }

private:
    void upAdjust(vector<Record>& rec, int n, int i) {
        int child;
        int parent = i;
        for(; parent*2+1 < n; child = parent){
            child = parent * 2 + 1;
            if (child + 1 <  n && rec[child + 1] < rec[child]) {
                child++;
            }

            if (rec[child] < rec[parent]) {
                rec[parent] = rec[child];
            }
            else {
                break;
            }
        }

        rec[i] = rec[child];
    }
   
};
// 还有一种方法是再使用一个有序的map，将出现的频率转换成map key，而数当作 value

// 对 map 的value 进行排序的方法
class Solution_1 {
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


int main()
{
    Solution a;
    vector<int> nums{1,1,2,2,3};
    vector<int> res = a.topKFrequent(nums, 2);
    return 0;
}