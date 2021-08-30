#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution_quick {
public:
    string minNumber(vector<int>& nums) {
        vector<string> str;
        for (int i = 0; i < nums.size(); ++i) {
            str.push_back(to_string(nums[i]));
        }

        quick(str, 0, str.size()-1);
        
        string res;
        for (auto s : str) {
            res.append(s);
        }
        return res;
    }
private:
    void quick(vector<string> &str, int l, int r) {
        if ( l >= r ) {
            return;
        }

        int i = l;
        int j = r;
        while (i < j)
        {
            while (i < j && str[j] + str[l] >= str[l] + str[j])
            {
                j--;
            }
            while (i < j && str[i] + str[l] <= str[l] + str[i])
            {
                i++;
            }
            swap(str[i], str[j]);            
        }
        swap(str[i], str[l]);
        quick(str, l, i-1);
        quick(str, i+1, r);
    }
};


bool cmp(string &x, string& y) {
    return x+y < y+x;
}
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> str;
        for (int i = 0; i < nums.size(); ++i) {
            str.push_back(to_string(nums[i]));
        }

        // lambda函数
        sort(str.begin(), str.end(), [](string& x, string& y){return x + y < y + x;});
        // cmp
        // 如果要把比较函数写出来的话，在C++中调用的回调函数必须写到外部去
        // sort(str.begin(), str.end(), cmp);
        string res;
        for (auto s:str) {
            res.append(s);
        }

        return res;
    }
};
int main() {
    Solution a;
    vector<int> nums{3,30,34,5,9};
    cout << a.minNumber(nums) << endl;
    return 0;
}