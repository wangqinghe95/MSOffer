
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        for (int n : nums)
            ret ^= n;
        int div = 1;
        while ((div & ret) == 0)
            div <<= 1;
        int a = 0, b = 0;
        for (int n : nums)
            if (div & n)
                a ^= n;
            else
                b ^= n;
        return vector<int>{a, b};
    }
};

// 异或(^)：相同为0，不同为1
// 与(&)：相同为1，不同为0
// 4 1 4 6
// 4 = 0100  1 = 0001 6 = 0110
// 4 ^ 1 = 0101 ^ 4 = 0001 ^ 6 = 0111 = ret
// div = 0001
// 4 & 0001 = 0 b ^ 4 = 0100 = b
// 1 & 0001 = 1 a ^ 1 = 0001 = a
// 4 & 0001 = 0 b ^ 4 = 0
// 6 & 0001 = 0 b ^ 6 = 6

/*
如果 x != y
那么 x^y 的结果中，不为1的位，在x和y中，肯定是一个为1，一个为0
*/