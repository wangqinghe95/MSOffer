/**/

class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> hash(130,0);
        for (int i = 0; i < s.size(); ++i) {
            hash[s[i] - '0'] ++;
        }

        char c(' ');
        for (int i = 0; i < s.size(); ++i) {
            if (hash[s[i] - '0'] == 1) {
                c = s[i];
                break;
            }
        }
        return c;
    }
};

// 99.35%
class Solution {
public:
    char firstUniqChar(string s) {
        int hash[130] = {0};
        for (int i = 0; i < s.size(); ++i) {
            hash[s[i]-'a']++;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (hash[s[i]-'a'] == 1) {
                return s[i];
            }
        }

        return ' ';
    }
};