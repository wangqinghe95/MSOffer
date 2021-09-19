
#include<iostream>
using namespace std;

class Solution {
public:
    int add(int a, int b) {
        while (b != 0)
        {
            int c = (a & b) << 1;
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