#include<iostream>
#include<vector>
using namespace std;

class Trie
{
public:
    Trie():childrens(2,nullptr){};
    void insert(int num)
    {
        Trie* cur = this;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (nullptr == cur->childrens[bit]){
                cur->childrens[bit] = new Trie();
            }
            cur = cur->childrens[bit];
        }
    }
    int search(int num)
    {
        Trie* cur = this;
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (nullptr != cur->childrens[!bit]) {
                ans |= (1 << i);
                cur = cur->childrens[!bit];
            }
            else {
                cur = cur->childrens[bit];
            }
        }
        return ans;
    }
private:
    vector<Trie*> childrens;
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = -1;

        Trie* root = new Trie();
        for (int num : nums) {
            root->insert(num);
        }
        for (int num : nums) {
            int cur_ans = root->search(num);
            max = max > cur_ans ? max : cur_ans;
        }
        return max;
    }
};

int main()
{
    vector<int> nums{14,70,53,83,49,91,36,80,92,51,66,70};

    Solution a;
    cout << a.findMaximumXOR(nums) << endl;
    return 0;
}