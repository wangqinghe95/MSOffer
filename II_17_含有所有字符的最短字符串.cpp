#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (n < m) {
            return "";
        }

        int cnt[60] = {0};
        for(int i = 0; i < m; ++i) {
            cnt[t[i]-'A']--;
        }

        int diff = 0;
        for (int x : cnt) {
            if (x != 0) {
                diff++;
            }
        }

        int min_len = INT_MAX;
        int min_start = 0;
        int left = 0;
        for (int right = 0; right < s.length(); ++right) {
            int x = s[right] - 'A';
            cnt[x]++;
            if (0 == cnt[x]) {
                diff--;
            }

            while (diff == 0) {
                if (right - left + 1 < min_len) {
                    min_start = left;
                    min_len = right - left + 1;
                }

                if (--cnt[s[left]-'A'] == -1) {
                    diff++;
                }
                left++;
            }
        }
        return INT_MAX != min_len ? s.substr(min_start, min_len) : "";
    }
};

int main() {
    Solution a;
    string s("ADOBECODEBANC");
    string t("ABC");
    cout << a.minWindow(s,t) << endl;
    return 0;
}