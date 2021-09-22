#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if (a.size() == 0) {
            return vector<int> {};
        }
        int size = a.size();
        vector<int> left(size);
        vector<int> right(size);
        vector<int> res(size);

        left[0] = right[size-1] = 1;
        for (int i = 1; i < size; ++i) {
            left[i] = left[i-1] * a[i-1];
        }

        for (int i = size - 2; i >= 0; --i) {
            right[i] = right[i+1] * a[i+1];
        }

        for (int i = 0; i < size; ++i) {
            res[i] = left[i] * right[i];
        }

        return res;
    }
};

int main() {
    Solution a;
    vector<int> num{1,2,3,4,5};
    a.constructArr(num);
    return 0;
}