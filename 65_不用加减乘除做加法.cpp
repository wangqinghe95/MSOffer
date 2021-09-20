
#include<iostream>
using namespace std;

class Solution {
public:
    int add(int a, int b) {
        while (b != 0)
        {
            int c = (unsigned int)(a & b) << 1; //C++的int左转移容易出现溢出问题
            a ^= b; //a is euqal with b is 0
            b = c;
        }
        return a;
        
    }
};

int main (){
    Solution a;
    cout << a.add(-3,-5) << endl;
    return 0;
}