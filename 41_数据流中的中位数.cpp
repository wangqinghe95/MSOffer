
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// 大小堆
//测试用例没有问题，但是leetcode提交超时了，可能是排序的时间复杂度超了
class MedianFinder_2 {
public:
    /** initialize your data structure here. */
    MedianFinder_2() {
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


class MedianFinder_4 {
private:
    priority_queue<int, vector<int>, less<int>> bigHeap;
    priority_queue<int, vector<int>, greater<int>> smallHeap;
public:
    /** initialize your data structure here. */
    MedianFinder_4() {

    }
    
    void addNum(int num) {
        if (bigHeap.size() == smallHeap.size()) {
            smallHeap.push(num);
            int value = smallHeap.top();
            smallHeap.pop();
            bigHeap.push(value);
        }
        else {
            bigHeap.push(num);
            int value = bigHeap.top();
            bigHeap.pop();
            smallHeap.push(value);
        }
    }
    
    double findMedian() {
        if (bigHeap.size() == smallHeap.size()) {
            return (double)(bigHeap.top() + smallHeap.top()) / 2.0;
        }
        else {
            return (double)bigHeap.top();
        }
    }
};

// 数据又超时了，看来不能使用堆排序，明天试一试归并排序，如果还不行就只能用algorithm自带的排序方法了
// 暴力破解不行，C++的排序都过不了最后一个测试点
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        if (arr.size() != 0) {
            arr.clear();
        }
        left = -1;
        right = -1;
    }
    
    void addNum(int num) {
        if (arr.size() == 0) {
            left = 0;
            right = 0;
        }
        else {
            if (left == right) {
                right++;
            }
            else {
                left++;
            }
        }
        arr.push_back(num);
    }
    
    double findMedian() {
        // heapSort(arr);
        // merge_sort(arr, arr.size());
        sort(arr.begin(), arr.end());
        return (arr[left] + arr[right]) / 2.0;
    }

private:
    vector<int> arr;
    int left;
    int right;

    // 归并排序也超时，看来不是代码的问题，是排序算法的问题
    void merge_sort(vector<int>&arr, int n){
        vector<int> tmp(arr.size(), 0);
        msort(arr, tmp, 0, n-1);
    }
    void msort(vector<int>&arr, vector<int>& tmp, int start, int end) {
        if (start < end) {
            int middle = (start + end) / 2;
            msort(arr, tmp, start, middle);
            msort(arr, tmp, middle+1, end);
            merge(arr, tmp, start, middle, end);
        }
    }
    void merge(vector<int>& arr, vector<int>& tmp, int start, int middle, int end) {
        int left_ = start;
        int right_ = middle+1;
        int s = start;

        while (left_ <= middle && right_ <= end)
        {
            // int value = arr[left] <= arr[right] ? arr[left] : arr[right];
            if (arr[left_] <= arr[right_]) {
                tmp[s++] = arr[left_++];
            }
            else {
                tmp[s++] = arr[right_++];
            }
        }

        while (left_ <= middle)
        {
            tmp[s++] = arr[left_++];
        }
        while (right_ <= end)
        {
            tmp[s++] = arr[right_++];
        }
        for (; start <= end; start++) {
            arr[start] = tmp[start];
        }    
    }

    void heapSort(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) {
            return;
        }
        for (int i = (n-2)/2; i >= 0; --i) {
            percdown(arr, n, i);
        }

        for (int i = n - 1; i >= 0; --i) {
            swap(arr[0], arr[i]);
            percdown(arr, i, 0);
        }
    }
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
            else {
                break;
            }
        }
        arr[parent] = x;
    }
};
int main(){
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    cout << "findMedian:" << obj->findMedian() << endl;
    obj->addNum(3);
    cout << "findMedian:" << obj->findMedian() << endl;
    obj->addNum(4);
    cout << "findMedian:" << obj->findMedian() << endl;
    obj->addNum(5);
    cout << "findMedian:" << obj->findMedian() << endl;
    obj->addNum(6);
    cout << "findMedian:" << obj->findMedian() << endl;
    obj->addNum(7);
    cout << "findMedian:" << obj->findMedian() << endl;
    obj->addNum(8);
    cout << "findMedian:" << obj->findMedian() << endl;
    obj->addNum(9);
    cout << "findMedian:" << obj->findMedian() << endl;
    obj->addNum(10);
    cout << "findMedian:" << obj->findMedian() << endl;

}