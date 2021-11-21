#include<unordered_map>
using namespace std;

/**
 * @brief 双向链表 + hash
 * @attention put 时，如果 key 已存在，更新val；
 *                    如果不存在，且curNum < totalNum，尾部添加
 *                    如果不存在，且curNum == totalNum，更新头节点
 *            get 时，如果存在，返回 key 值对应的 val
 *           put、get 操作都会将访问的数据移动到链表尾部
 * @note 移动和添加节点时注意链表的双向节点
 */

class LRUCache {
public:
    LRUCache(int capacity) {
        mTotalNum = capacity;
        mCurNum = 0;

        dummy = new Node();
        tail = dummy;
    }
    
    int get(int key) {
        if (!mKeyToNode.count(key)) {
            return -1;
        }

        MoveCurNodeToTail(key);
        return mKeyToNode[key]->val;
    }
    
    void put(int key, int value) {
        if (mKeyToNode.count(key)) {
            mKeyToNode[key]->val = value;
            MoveCurNodeToTail(key);
        }
        else if (mCurNum < mTotalNum){
            addToTail(key, value);
            mCurNum++;
        }
        else {
            updateHead(key, value);
        }
    }
private:
    void MoveCurNodeToTail(int key) {
        Node* curNode = mKeyToNode[key];
        if (curNode == tail) {
            return;
        }

        curNode->pre->next = curNode->next;
        curNode->next->pre = curNode->pre;
        curNode->next = nullptr;
        tail->next = curNode;
        curNode->pre = tail;
        tail = curNode;
    }

    void addToTail(int key, int value) {
        Node* curNode = new Node(key, value);

        tail->next = curNode;
        curNode->pre = tail;
        tail = curNode;

        mKeyToNode[key] = curNode;
    }

    void updateHead(int key, int val) {
        mKeyToNode.erase(dummy->next->key);
        dummy->next->key = key;
        dummy->next->val = val;

        mKeyToNode[key] = dummy->next;
        MoveCurNodeToTail(key);
    }
private:
    struct Node {
        int key = 0;
        int val = 0;
        Node* pre = nullptr;
        Node* next = nullptr;
        Node(){}
        Node(int _key, int _val) : key(_key), val(_val) {}
    };
    unordered_map<int, Node*> mKeyToNode;

    unsigned int mTotalNum;
    unsigned int mCurNum;

    Node* dummy;
    Node* tail; 
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */