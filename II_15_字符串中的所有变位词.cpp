
/*
14 题的变种
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        if (m > n) {
            return vector<int>{};
        }

        int cnt[26] = {0};
        for (int i = 0; i < m; ++i) {
            --cnt[p[i]-'a'];
        }

        int left = 0;
        vector<int> res;
        for (int right = 0; right < n; ++right) {
            int x = s[right] - 'a';
            ++cnt[x];
            while (cnt[x] > 0) {
                --cnt[s[left]-'a'];
                ++left;
            }

            if (right-left+1 == m) {
                res.push_back(left);
            }
        }

        return res;
    }
};