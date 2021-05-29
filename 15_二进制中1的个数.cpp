

// 方法1
/*
* n & 1 的结果是检测二进制的 n 最右侧的数组是否为 1
* 9 = 1001， 9 & 1 = 1，8 = 1000， 8 & 1 = 0
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n > 0)
        {
            res += (n & 1);
            n >>= 1;
        }
        return res;
        
    }
};

// 方法2
/*
 *  n & (n-1) 的结果是，会将二进制的 n 的最右边的 1 给消掉  
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while( n > 0){
            res++;
            n &= (n-1);
        }
        return res;
    }
};