/*
约瑟夫环问题：
    [0,n-1] 个数，每隔 m 个数删除一个数字，求最后一个数字是什么？
    设输入[n,m]的问题解为 f(n,m)，那么就有
    [n,m] 问题，即 0,1,2... n-1 的解为 f(n)
    [n-1,m]问题， 0，1，2，...n-2 的解为 f(n-1)
    依次类推
    [1,m] 问题, 0 的解 为 f(1) = 0

    1、[n,m] 问题，删除第 m 个数后，列表是
        0,1,2,3,..., m-2, m,... n
    2、但是 m 可能会大于 n，所以最后形成的环为 
        0,1,2,3,..., (m-2)%n, m%n,... n
    3、把 m % n = t 换入到列中,删除的数字是(m-1)%n = t-1
        0,1,2,3,..., t-2, t,... n
    4、因为删除 t 后，继续从 t 开始算起，所以队列可以转换成 
        t,... n,0,1,..t-3,t-2
    
    所以从 [n,m] 删除前的队列，到删除后的队列变化为
    f(n-1)  f(n)删除一个数字后
    0       t+0
    1       t+1
    ...     ...
    n-3     t-3
    n-2     t-2
    f(n) -> f(n-1) 的映射是关键 ((n-2)+t)%n = t-2 
    f(n) = (f(n-1)+t)%n 
         = (f(n-1)+(m)%n)%n
         = (f(n-1)+m)%n

*/

// 递归
#include<iostream>
using namespace std;

class Solution {
public:
    int lastRemaining(int n, int m) {
        f(n,m);        
    }
    int f(int n,int m) {
        if (n == 1) {
            return 0;
        }
        int x = f(n-1,m);
        return (x+m) % n;
    }
};

// 迭代
class Solution {
public:
    int lastRemaining(int n, int m) {
        int x = 0;
        for (int i = 2; i <= n; ++i) {
            x = (m+x) % i;
        }  
        return x;
    }
};

int main() {

}