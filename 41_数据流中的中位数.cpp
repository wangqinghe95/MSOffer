
#include<iostream>
#include<vector>
using namespace std;

// 大小堆
//测试用例没有问题，但是超时了，可能是排序的时间复杂度超了
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        if (!min_heap.empty()){
            min_heap.clear();
        }
        if (!max_heap.empty()) {
            max_heap.clear();
        }
    }
    
    void addNum(int num) {
        if (max_heap.size() != min_heap.size()) {
            add_min_heap(min_heap, num);
            add_max_heap(max_heap, poll_min_heap(min_heap));
        }
        else {
            add_max_heap(max_heap, num);
            add_min_heap(min_heap, poll_max_heap(max_heap));
        }
    }
    
    double findMedian() {
        return max_heap.size() != min_heap.size() ? get_peek(min_heap) : (get_peek(min_heap) + get_peek(max_heap)) / 2.0;
    }
private:
    vector<int> min_heap;
    vector<int> max_heap;

    int get_peek(vector<int>& arr){
        return arr[0];
    }
    int poll_min_heap(vector<int>&arr) {
        int num = arr[0];
        arr[0] = arr[arr.size()-1];
        arr.pop_back();
        updown(arr, arr.size(), 0);

        return num;
    }

    void add_min_heap(vector<int>&arr, int num) {
        arr.push_back(num);
        int n = arr.size();
        if (n < 2) {
            return;
        }
        for (int i = (n-2)/2; i >= 0; --i) {
            updown(arr, n, i);
        }
    }

    void updown(vector<int>&arr, int n, int i) {
        int parent = i;
        int x = arr[parent];
        int child;
        for (; parent*2+2 <= n; parent = child) {
            child = parent*2+1;
            if (child+1 < n && arr[child+1] < arr[child]) {
                child++;
            }
            if (arr[child] < x) {
                arr[parent] = arr[child];
            }
            else{
                break;
            }
        }
        arr[parent] = x;        
    }


    int poll_max_heap(vector<int>&arr) {
        int num = arr[0];
        arr[0] = arr[arr.size()-1];
        arr.pop_back();
        percdown(arr, arr.size(), 0);
        return num;
    }
    void add_max_heap(vector<int>& arr, int num) {
        arr.push_back(num);
        int n = arr.size();
        if (n < 2) {
            return;
        }
        for (int i = (n-2)/2; i >= 0; --i) {
            percdown(arr, n, i);
        }
    }
    //大顶堆
    void percdown(vector<int>& arr, int n, int i) {
        int parent = i;
        int x = arr[parent];
        int child;
        for (; parent*2+2 <= n; parent = child) {
            child = parent*2+1;
            if (child+1 < n && arr[child+1] > arr[child]) {
                child++;
            }
            if (arr[child] > x) {
                arr[parent] = arr[child];
            }
            else{
                break;
            }
        }
        arr[parent] = x;
    }
};

//将加入的数据进行插入排序
class MedianFinder_1 {
public:
    /** initialize your data structure here. */
    MedianFinder_1() {
        if (!res.empty()) {
            res.clear();
        }
        mid = 0;
    }
    
    void addNum(int num) {
        res.push_back(num);
        insertSort(num);
        mid = (res.size()-1) / 2;
    }
    
    double findMedian() {
        if( res.size() & 1) {   // odd
            return (double)(res[mid]);
        }
        else {  // even
            return (double)((double)(res[mid]+(double)res[mid+1])/2);
        }
    }
private:
    void insertSort(int num) {
        int i = res.size()-1;
        for (; i > 0 && res[i-1] > num; --i) {
            res[i] = res[i-1];
        }
        res[i] = num;
    }
private:
    vector<int> res;
    int mid;
};


int main(){
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    cout << "findMedian:" << obj->findMedian() << endl;
    obj->addNum(3);
    cout << "findMedian:" << obj->findMedian() << endl;
}