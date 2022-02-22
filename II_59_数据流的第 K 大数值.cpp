#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

class KthLargest_1 {
public:
    KthLargest_1(int k, vector<int>& nums) {
       maxK = k;
       for (auto &x : nums) {
           add(x);
       } 
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > maxK) {
            q.pop();
        }
        return q.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> q;
    int maxK;
};

// 维持一个最小堆也不对，因为更新数组时，不能保证顶替的数据是最小的数据
// 堆排序维持一个容量为k的数组，然后返回堆顶元素的思路是错误的
// 求的是数据流的第K大的
// 超出时间限制
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        maxK = k;
        for (int i = 0; i < nums.size(); ++i) {
            int x = add(nums[i]);
            //printf(" %d", x);
        }
    }
    
    int add(int val) {
        arr.push_back(val);
        heap(arr, arr.size());
        if (arr.size() > maxK) {
           swap(arr[maxK], arr[0]);
           arr.pop_back();
           heap(arr, arr.size());
        }
        return arr[0];
    }
private:
    void heap(vector<int>& arr, int n)
    {
        if (n < 2) {
            return;
        }

        for (int i = (n-2)/2; i >= 0; --i) {
            percdown(arr, n, i);
        }

        for (int i = n-1; i > 0; --i) {
            swap(arr[i], arr[1]);
            percdown(arr, i, 0);
        }
    }

    void percdown(vector<int>& arr, int n, int parent)
    {
       int child ;
       int x = arr[parent];
       for (; parent * 2 + 1 < n; parent = child) {
           child = parent * 2 + 1;
           if (child + 1 < n && arr[child + 1] < arr[child]) {
               child += 1;
           }

           if (arr[child] < x) {
               arr[parent] = arr[child];
           }
           else {
               break;
           }
       } 
        arr[parent] = x;
    }
private:
    int maxK;
    vector<int> arr;
};


int main()
{
    int k = 3;
    vector<int> nums{4,5,8,2};
    KthLargest* obj = new KthLargest(k, nums);
    cout << obj->add(3)  << endl;
    cout << obj->add(5)  << endl;
    cout << obj->add(10)  << endl;
    cout << obj->add(9)  << endl;
    cout << obj->add(4)  << endl;
    return 0;
}