/*
回朔法：将string的各个位置的字符交换位置
*/
#include<string>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    vector<string> vec_str;
    void bfs(string str, int x) {
        if (x == str.size() - 1) {
            vec_str.push_back(str);
            return;
        }

        set<int> st;
        for (int i = x; i < str.size(); ++i) {
            if (st.find(str[i]) != st.end()) {
                continue;
            }

            st.insert(str[i]);
            swap(str[i], str[x]);
            bfs(str, x+1);
            swap(str[i], str[x]);
        }
    }
    vector<string> permutation(string s) {
        bfs(s, 0);
        return vec_str;
    }
};

int main(){
    string s("abc");
    Solution a;
    a.permutation(s);
    return 0;
}