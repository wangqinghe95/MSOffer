/*
字符串是‘单调递增’，意思是左边是0，右边是1，数字的个数可以是 0
那么就可以这样考虑
从左边开始扫描数组，如果是 0 ，那么将这个 0 左侧的所有 1 反转成 0 不就达到了单调递增的性质了
0 也可以反转成 1，那么什么时候由 0 反转成 1 呢
判断的条件就是，如果反正当前 0 之前的 1 的个数大于需要反转的 0 的个数

简单的描述为：
选取一个点，记录当前点之前 1 的个数，以及之前需要反转的次数 + 加上反转当前的 0 的次数
*/

class Solution_1 {
public:
    int minFlipsMonoIncr(string s) {
        int pre1 = 0;
        int ans = 0;
        for(char c : s) {
            if(c == '0'){
                ans = (ans+1) < pre1 ? ans + 1 : pre1;
            }
            else{
                pre1++;
            }
        }
        return ans;
    }
};

/*
* 前缀和
* 针对一个‘单调递增’的需求，可以这样考虑字符串的每一个字符：
* 该字符之前的所有 1 变成 0，该字符之后的所有 0 变成 1，就能满足单调递增的要求
* 如果统计该字符之前的所有 0 和 1，这个过程就是统计前缀和后缀的思想
*/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int *pre = new int[n+1];
        int *post = new int[n+1];
        pre[0] = 0;
        post[n] = 0;

        for(int i = 0; i < n; ++i) {
            pre[i+1] = s[i] == '1' ? pre[i] + 1 : pre[i];
            int postIndex = n - i;
            post[postIndex - 1] = s[postIndex] == '0' ? post[postIndex] + 1 : post[postIndex];
        }

        int ans = pre[0] + post[0];
        auto min = [](int a, int b) {
            return a > b ? b : a;
        };
        for(int i = 1; i < n; ++i){
            ans = min(ans, pre[i]+post[i]);
        }

        return ans;
    }
};