#include<iostream>
using namespace std;

/*
双指针：
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n > m) {
            return false;
        }

        int cnt[26] = {0};
        for (int i = 0; i < n; i++) {
            --cnt[s1[i]-'a'];
        }

        int left = 0;
        for (int right = 0; right < m; ++right) {
            int x = s2[right] - 'a';
            ++cnt[x];

            while (cnt[x] > 0) {
                --cnt[s2[left]-'a'];
                ++left;
            }

            if (right - left + 1 == n) {
                return true;
            }
        }

        return false;
    }
};

/*
变位词的含义就是只要两个字符串的字符数量能相同，就符合条件
那么在比较两个字符串的字符数量的过程中，就可以通过滑动窗口的方法，
用相对差值来记录两个字符串字符相差的个数了
*/
class Solution_2 {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n > m) {
            return false;
        }

        int cnt[26] = {0};
        for (int i = 0; i < n; ++i) {
            cnt[s1[i] - 'a']--;
            cnt[s2[i] - 'a']++;
        }

        // diff 不为 0，表示还有相差的字符
        int diff = 0;
        for (int c : cnt) {
            if (c != 0){
                diff++;
            }
        }

        if (0 == diff) {
            return true;
        }

        for (int i = n; i < m; ++i) {
            // 使用滑动窗口比较[i,i-n]子字符串的字串个数
            // x 表示要减去的字符，y表示要加入的字符串
            // 减去前如果 cnt[x] == 0，然后加上一个字符，表示cnt[x] == 1，意味着有一个字符数量不匹配
            // 加上同理，都需要做相应的处理
            int x = s2[i]-'a';
            int y = s2[i-n]-'a';

            if (x == y) {
                continue;
            }
            if (0 == cnt[x]) {
                diff++;
            }
            cnt[x]++;
            if (0 == cnt[x]) {
                --diff;
            }

            if (0 == cnt[y]) {
                ++diff;
            }
            --cnt[y];
            if (0 == cnt[y]) {
                --diff;
            }

            if (0 == diff) {
                return true;
            }
        }

        return false;
    }

};

/*
滑动窗口：因为变位词不会改变字符串中的每个字符的个数，
所以只有当两个字符串的每个字符个数均相等时，一个字符串才是另一个字符串的变位词
*/
class Solution_1 {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if (n > m) {
            return false;
        }

        int hash_s1[30] = {0};
        int hash_s2[30] = {0};
        for (int i = 0; i < n; ++i) {
            hash_s1[s1[i]-'a']++;
            hash_s2[s2[i]-'a']++;
        }

        if (hashSame(hash_s1, hash_s2)) {
            return true;
        }

        for (int i = n; i < m; ++i) {
            hash_s2[s2[i]-'a']++;
            hash_s2[s2[i-n]-'a']--;
            if (hashSame(hash_s1,hash_s2)) {
                return true;
            }
        }
        return false;
    }
private:
    bool hashSame(const int* hash1, const int *hash2) {
        for (int i = 0; i < 30; ++i) {
            if (hash1[i] != hash2[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s1("ab");
    string s2("eidbaooo");
    Solution a;
    cout << a.checkInclusion(s1,s2) << endl;
    return 0;
}