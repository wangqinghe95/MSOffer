
/**
 * @brief 有效词，字母个数和类型一致即可
 * @details hash记录两个字符串的字母类型和数量的差别
 * @attention 一样的字符串是要返回 false 的
 * 
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int hash[30] = {0};
        bool bIsSame = true;
        for (int i = 0; i < s.size(); ++i) {
            if (bIsSame && s[i] != t[i]) {
                bIsSame = false;
            }

            hash[s[i] - 'a']++;
            hash[t[i] - 'a']--;
        }

        if (bIsSame) {
            return false;
        }

        for (int i = 0; i < 30; ++i) {
            if (hash[i] != 0) {
                return false;
            }
        }

        return true;
    }
};