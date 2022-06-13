#include<iostream>
#include<vector>
using namespace std;
class Trie
{
public:
    Trie():bEnd(false),childrens(26,nullptr){}
    void insert(string &word){
        Trie* node = this;
        for (auto ch : word) {
            if (nullptr == node->childrens[ch-'a']) {
                node->childrens[ch-'a'] = new Trie();
            }
            node = node->childrens[ch-'a'];
        }
        node->bEnd = true;
    }
    bool IsEnd() const {
        return bEnd;
    }
    Trie* getChildByIndex(int j) const {
        return childrens[j];
    }
private:
    bool bEnd;
    vector<Trie*> childrens;
};
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        mTrieRoot = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for (auto word : dictionary) {
            mTrieRoot->insert(word);
        }
    }
    
    bool search(string searchWord) {
        return dfs(mTrieRoot, searchWord, 0, 0);
    };
private:
    bool dfs(Trie* node, string& word, int index, int nReplaceNum) {
        if (nullptr == node) {
            return false;
        }

        if (node->IsEnd() && index == word.size() && 1 == nReplaceNum) {
            return true;
        }

        if (index < word.size() && nReplaceNum <= 1) {
            bool bFound = false;

            // check Trie* node's listlink match with  
            for (int j = 0; j < 26 && !bFound; ++j) {
                int nowReplaceNum = (j == word[index]-'a' ? nReplaceNum : nReplaceNum + 1);
                bFound = dfs(node->getChildByIndex(j), word, index+1, nowReplaceNum);
            }
            return bFound;
        }
        return false;
    }
    Trie* mTrieRoot;
};

int main()
{
    vector<string> dictionary{"hello", "leetcode"};
    MagicDictionary* obj = new MagicDictionary();
    obj->buildDict(dictionary);
    bool param_2 = obj->search("hello");
    bool param_3 = obj->search("hhllo");
    bool param_4 = obj->search("hell");
    bool param_5 = obj->search("leetcoded");
    cout << param_2 << endl;
    cout << param_3 << endl;
    cout << param_4 << endl;
    cout << param_5 << endl;
    return 0;
}