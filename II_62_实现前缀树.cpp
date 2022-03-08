#include<iostream>
#include<vector>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie():children(26),isEnd(false) {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for(char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = searchPrex(word);
        return node != nullptr && node->isEnd == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = searchPrex(prefix);
        return node != nullptr;
    }
private:
    Trie* searchPrex(string prefix){
        Trie* node = this;
        for(char ch : prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }
private:
    vector<Trie*> children;
    bool isEnd;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */