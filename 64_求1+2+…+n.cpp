/*
不能使用if、while，三目判断运算符
*/

class Solution {
public:
    int sumNums(int n) {
        n && (n+=sumNums(n-1));
        return n;
    }
};