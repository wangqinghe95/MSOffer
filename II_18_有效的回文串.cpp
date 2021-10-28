

// 100%

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            while (left < right && !isValid(s[left])){
                left++;
            }
            while(left < right && !isValid(s[right])){
                right--;
            }

            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
private:
    bool isValid(char& c) {
        if (c >= '0' && c <= '9') {
            return true;
        }
        else if (c >= 'a' && c <= 'z') {
            return true;
        }
        else if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
            return true;
        }
        return false;
    }
};

// 88.7
class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        for (int i = 0; i < s.length(); ++i) {
            if (isValid(s[i])) {
                res.push_back(s[i]);
            }
        }

        int n = res.length();
        for (int i = 0; i < n / 2; ++i) {
            if (res[i] != res[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
private:
    bool isValid(char& c) {
        if (c >= '0' && c <= '9') {
            return true;
        }
        else if (c >= 'a' && c <= 'z') {
            return true;
        }
        else if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
            return true;
        }
        return false;
    }
};