
/*
原地反转
*/

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin()+n);
        reverse(s.begin()+n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

/*
字串剪切
*/

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n,s.size()-n) + s.substr(0,n);     
    }
};
