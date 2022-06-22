#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    Solution(vector<int>& w) {
        m_pre.resize(w.size());
        m_total = 0;  // must initialize m_total here, otherwise it can't pass one case which have many inputs times
        for(int i = 0; i < w.size(); ++i) {
            m_total += w[i];
            m_pre[i] = m_total;
        }
    }
    
    int pickIndex() {
        int rnd =  rand() % m_total;
        int left = 0;
        int right = m_pre.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (m_pre[mid] > rnd) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
private:
    vector<int> m_m_pre;
    int m_total;
};

int main()
{

}