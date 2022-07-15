

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int count[1001] = {0};
        vector<int> res;
        for (int& val : arr1) {
            count[val]++;
        }

        for (int& val : arr2) {
            if (count[val] != 0){
                setDataToRes(res, val, count[val]);
                count[val] = 0;
            }
        }

        for (int i = 0; i < 1001; ++i) {
            if(count[i] != 0) {
                setDataToRes(res, i, count[i]);
            }
        }

        return res;
    }
private:
    void setDataToRes(vector<int>& res, int val, int count) {
        for (int i = 0; i < count; ++i){
            res.push_back(val);
        }
    }
};