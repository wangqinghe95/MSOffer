// 
class Trie
{
public:
    int value;
    vector<Trie*> childrens;
public:
    Trie(/* args */):value(0), childrens(26,nullptr){};
    void insert(const string& word,int val) {
        Trie* node = this;
        for (auto &ch : word)
        {
            if (nullptr == node->childrens[ch-'a']) {
                node->childrens[ch-'a'] = new Trie();
            }
            node = node->childrens[ch-'a'];
        }
        node->value = val;
    }
    Trie* getNode(char ch) const {
        return childrens[ch-'a'];
    }
    Trie* getNode(int index) const {
        return childrens[index];
    }
    int getValue() const{
        return value;
    }

    ~Trie();
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        mRoot = new Trie();
    }
    
    void insert(string key, int val) {
        mRoot->insert(key,val);
    }
    
    int sum(string prefix) {
        Trie* cur = mRoot;
        for (int i = 0; i < prefix.size(); ++i) {
            if (nullptr != cur->getNode(prefix[i]))
            {
                cur = cur->getNode(prefix[i]);
            }
            else 
            {
                return 0;
            }
        }
        if (nullptr != cur) {
            return preTraversal(cur);
        }

        return 0;
    }
private:
    int preTraversal(Trie* node) {
        if (nullptr == node) {
            return 0;
        }

        int value = 0;
        if (0 != node->getValue()) {
            value += node->getValue();
        }

        for (int i = 0; i < 26; ++i) {
             Trie *now = node->getNode(i);
            if (now != nullptr)
            {
                value += preTraversal(now);
            }
        }

        return value;

    }
    Trie* mRoot;
};