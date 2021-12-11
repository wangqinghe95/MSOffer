#include<vector>
#include<string>
#include<iostream>
using namespace std;

/**
 * @brief 单词的排序根据下方根据的自定义的字典序
 * @details 先使用hash表将自定义的字典序进行排序
 *          然后从words按照顺序比较（后一个肯定要比前一个字典序小）
 *          字典序小的含义是前面一个单词的字符在字典中（hash）数字要更小
 *          需要注意的是不需要比较完整个单词，只需要第i个单词字典序小，就表示前面单词的字典序小
 *          如果前面n个单词都相等，单词长度长的单词字典序大
 * 
 */
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        init(order);
        bool bAlph = true;
        for (int i = 1; i < words.size(); ++i) {
            if (!isAlphOrder(words[i-1], words[i])) {
                return false;
            }
        }    
        return true; 
    }
private:
    void init(string& order) {
        for (int i = 0; i < order.size(); ++i) {
            hash[order[i]-'a'] = i + 1;
        }
    }
    // 返回 true 表示符合字典序
    // 返回 false 表示 s1 > s2 ，不符合字典序
    bool isAlphOrder( string& s1,  string& s2) {
        int min_cnt = s1.size() < s2.size() ? s1.size() : s2.size();
        for (int i = 0; i < min_cnt; ++i) {
            int a = hash[s1[i]-'a'];
            int b = hash[s2[i]-'a'];
            // if (hash[s1[i]-'a'] > hash[s2[i]-'a']) {
            if (a > b) {
                return false;
            }
            else if (a < b){
                return true;
            }
        }

        if (s1.size() > s2.size()) {
            return false;
        }
        else {
            return true;
        }
    }
private:
    int hash[26] = {0};
};

int main() {
    Solution a;
    vector<string> words{"word","world","row"};
    string order("worldabcefghijkmnpqstuvxyz");
    cout << a.isAlienSorted(words, order) << endl;
    return 0;
}