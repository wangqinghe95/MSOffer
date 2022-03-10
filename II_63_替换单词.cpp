#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Trie
{
public:
    Trie():isEnd(false),chilren(26,nullptr){};
    void insert(const string &str) {
        Trie* node = this;
        for(auto &ch : str) {
            if (node->chilren[ch-'a'] == nullptr) {
                node->chilren[ch-'a'] = new Trie();
            }
            node = node->chilren[ch-'a'];
        }
        node->isEnd = true;
    }

    int countPrefixLen(const string& word){
        Trie* node = this;

        // 节点的长度从1开始，但是len从0开始，所以node指向下一位后再判断是否返回是正确的
        int len = 0;
        for (auto &ch : word) {
            if (node->chilren[ch-'a'] == nullptr) { // return a value that are not zero must be finding a Trie whose isEnd is true
                return 0;
            }
            len++;
            node = node->chilren[ch-'a'];
            if (node->isEnd == true){
                return len;
            }
        }
        return 0;
    }

private:
    bool isEnd;
    vector<Trie*> chilren;
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* node = new Trie();
        for(auto &word : dictionary) {
            node->insert(word);
        }
        
        vector<string> words{""};
        for (auto& ch : sentence) {
            if (' ' != ch) {
                words.back().push_back(ch);
            }
            else {
                words.push_back("");
            }
        }
        
        vector<string> ret;
        for (auto& word : words) {
            int len = node->countPrefixLen(word);
            if (0 == len){
                ret.emplace_back(word);
            }
            else {
                ret.emplace_back(word.substr(0,len));
            }
        }
        
        string res;
        for(auto& word : ret) {
            res += word;
            res += " ";
        }
        res.pop_back();
        return res;
    }
};


int main() {
   vector<string> dic{"cat","bat","rat"};
   string sentence("the cattle was rattled by the battery");
   Solution a;
   cout << a.replaceWords(dic, sentence) << endl;
   return 0;
}