#include<vector>
using namespace std;


/*
最小堆：
    1、对arr排序，建立最小堆
    2、然后再交换数组首尾元素 n-k 次
    3、那么数组的倒数第 n-k-1,n-k 就是数组中全部第 k 小个数
*/
class Solution_heap2 {
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
// 20210824 修正，因为在 child<=n 写错
class Solution_heap1 {
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
                // max_heap[0] = max_heap[k - 1];
                // max_heap[k-1] = arr[i];
                max_heap[0] = arr[i];
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
            if (child + 1 < n && arr[child] < arr[child+1]) {
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

/*
 * 快排之后取前n个数 
 */

 /*
* 快排：根据快排性质可知，在对于每一个 pivotpos 
* 每次排序后所有小于该数的值都位于该数之前（非递减），反之位于其后
* 所以如果快排的 pivotpos 的下标是 k 的话，刚好满足该情况
*/

class Solution_quick1 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quick(arr, 0, arr.size()-1, k);
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i]);
        }
        return res;
    }

private:
    void quick(vector<int>& arr, int low, int high,int k) {
#if 0
        //快排,基础解法，将整个数组排序
        if (low < high) {
            int pivotpos = partition(arr, low, high);
            quick(arr, low, pivotpos-1);
            quick(arr, pivotpos+1, high);
        }
#else
        // 中间判断，减少排序次数
        // 根据快排性质简化流程
        if (low < high) {
            int pivotpos = partition(arr, low, high);
            if (pivotpos == k){
                return;
            }
            else {
                quick(arr, low, pivotpos-1, k);
                quick(arr, pivotpos+1, high, k);
            }
        }      
#endif 
    }

    int partition(vector<int>& arr, int low, int high) {
        int tmp = arr[low];
        while(low < high) {
            while(low < high && arr[high] >= tmp) {
                high--;
            }
            arr[low] = arr[high];
            while(low < high && arr[low] <= tmp) {
                low++;
            }
            arr[high] = arr[low];
        }
        arr[low] = tmp;
        return low;
    }
};

int main() {
    vector<int> arr{0,1,1,2,4,4,1,3,3,2};

    int k = 6;
    /*
    Solution_Offer1 a;
    a.getLeastNumbers(arr, k); */
    // Solution_quick1 a;
    // a.getLeastNumbers(arr, k);
    Solution_heap1 heap;
    heap.getLeastNumbers(arr, k);
    return 0;
}