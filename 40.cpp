#include<vector>
using namespace std;


/*
最小堆：
    1、对arr排序，建立最小堆
    2、然后再交换数组首尾元素 n-k 次
    3、那么数组的倒数第 n-k-1,n-k 就是数组中全部第 k 小个数
*/
class Solution_Offer1 {
public:
    void updown(vector<int> &arr,int n, int i) {
        
        int parent = i;
        int x = arr[parent];
        int child ; // 初始化child数据
        for (; parent * 2 + 2 <= n; parent = child) {
            child = parent * 2 + 1; // 每次更换
            if (child + 1 < n && arr[child+1] < arr[child]) {
                child++;
            }

            if (arr[child] > x) {
                break;
            }
            else {
                arr[parent] = arr[child];
            }
        }
        arr[parent] = x;
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.size() < 2) {
            return arr;
        }

        int n = arr.size();
        for (int i = (n-2)/2; i >= 0; i--) {    //第一步
            updown(arr, n ,i);
        }

        for (int i = n-1; i >= n-k; i--) {    //第二步
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            updown(arr, i, 0);
        }

        vector<int> tmp;
        for(int i = 0; i < k; ++i) {    //第三步
            tmp.push_back(arr[n-i-1]);
        }

        return tmp;
    }
};


/*
最小堆：
    1、建一个容量为k的最大堆 res
    2、遍历arr数组，把arr数据往 res 中添加
    3、如果 res 容量小于 k，直接添加该数值，并且保持最大堆状态
    4、如果 res 容量到达 k，新来的数据和堆顶元素比较，如果比堆顶元素小，则将数组最后一个数值替换堆顶元素，并将该元素添加到第k位
    5、再循环一次找到最大值放入到堆顶

*/

// 这种方法本地运行没问题，leetcode提交报了栈溢出
class Solution_Offer40 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> max_heap(k,0);
        if (k == 0) {
            return max_heap;
        }
        for (int i = 0; i < k; ++i) {
            max_heap[i] = arr[i];
        }

        if (k == 1) {
            return max_heap;
        }

        adjustMaxHeap(max_heap, k);

        for (int i = k; i < arr.size(); ++i) {
            if (arr[i] < max_heap[0]) {
                max_heap[0] = max_heap[k - 1];
                max_heap[k-1] = arr[i];
                adjustMaxHeap(max_heap, k);
            }
        }
        return max_heap;
    }
private:
    void adjustMaxHeap(vector<int> &arr, int k) {
        for (int i = (k-2)/2; i >= 0; --i) {
            percdown(arr, k, i);
        }
    }
    void percdown(vector<int>& arr, int n, int i)  {
        int parent = i;
        int x = arr[parent];
        int child;
        for(; parent * 2 + 2 <= n; parent = child) {
            child = parent * 2 + 1;
            if (child + 1 <= n && arr[child] < arr[child+1]) {
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

class Solution_Offer40_1
{
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quick(arr, k);
    }
private:
    void quick(vector<int> &arr, int l, int k) {
        
    }

};

int main() {
    vector<int> arr{3,2,1};
    int k = 2;
    /*
    Solution_Offer1 a;
    a.getLeastNumbers(arr, k); */
    Solution_Offer40 a;
    a.getLeastNumbers(arr, k);
    return 0;
}