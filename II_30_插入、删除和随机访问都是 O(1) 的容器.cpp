#include<vector>
#include<unordered_map>
using namespace std;

/**
 * @brief 
 * @attention 这道题的关键点在于：插入删除和随机访问的时间复杂度都是O(1)
 *              这就意味着不能单单使用链表和数组来实现这个类
 *              本题使用的是hash来完成这个要求的
 * @insert：插入时将 value 和 arr.size() 对应到 hash 中去
 * @delete：删除时，会将要删除的值的下标赋值给 arr.size() 下标的值中去
 *          然后移除掉hash表中的该值，并且将arr的back值覆盖掉 value 值
 *          （通过hash表找到该值在arr的下标），最后pop出去  
 */
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hash.count(val)) {
            return false;
        }

        hash[val] = arr.size();
        arr.push_back(val);

        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!hash.count(val)) {
            return false;
        }

        hash[arr.back()] = hash[val];
        arr[hash[val]] = arr.back();

        hash.erase(val);
        arr.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return arr[rand()%arr.size()];
    }
private:
    unordered_map<int,int> hash;
    vector<int> arr;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */