#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Trie
{
public:
    Trie():bHaveChildrens(false),childrens(26,nullptr){}
    Trie* insert(const string& word)
    {
        Trie* node = this;
        for (int i = word.size()-1; i >= 0; --i) {
            int index = word[i] - 'a';
            if (nullptr == node->childrens[index]) {
                node->childrens[index] = new Trie();
            }
            node->bHaveChildrens = true;
            node = node->childrens[index];
        }
        // node->bHaveChildrens = true;
        return node;
    }
    bool isEnd() const{
        return !bHaveChildrens;
    }
private:
    bool bHaveChildrens;
    vector<Trie*> childrens;
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        Trie* node = new Trie();
        unordered_map<Trie*,int> node2index;

        for (int i = 0; i < words.size(); ++i) {
            Trie* cur = node;
            cur = cur->insert(words[i]);
            node2index[cur] = i;
        }

        int ans = 0;
        for (auto& iter : node2index) {
            if (true == iter.first->isEnd()) {
                ans += words[iter.second].length()+1;
            }
        }

        return ans;
    }
};

int main()
{
    vector<string> words{"time", "me","bell"};
    Solution a;
    cout << a.minimumLengthEncoding(words) << endl;
    return 0;
}