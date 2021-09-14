#include<iostream>
#include<queue>

using namespace std;

class MaxQueue {
public:
    MaxQueue() {
        while (!que.empty()) {
            // que.pop_front();
            que.pop();
        }

        while (!max_que.empty()) {
            // max_que.pop_front();
            max_que.pop_back();
        }
    }
    
    int max_value() {
        if (max_que.empty()) {
            return -1;
        }
        return max_que[0];
    }
    
    void push_back(int value) {
        que.push(value);
        while (!max_que.empty() && max_que[0] < value)
        {
            max_que.pop_front();
        }
        
        while (!max_que.empty() && max_que[max_que.size()-1] < value)
        {
            max_que.pop_back();
        }
       
        max_que.push_back(value);
    }
    
    int pop_front() {
        if (que.empty()) {
            return -1;
        }
        int value = que.front();
        if (value == max_que[0]) {
            max_que.pop_front();
        }
        que.pop();
        return value;
    }
private:
    queue<int> que;
    // queue<int> max_que;
    deque<int> max_que;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

void test1();
void test2();

int main() {
  test2();
  return 0; 
}
/*
["MaxQueue","pop_front","push_back","max_value","max_value","push_back","max_value","push_back",
"max_value","push_back","max_value","max_value",
"push_back",
"max_value","pop_front","pop_front",
"push_back","pop_front","max_value","max_value",
"push_back","pop_front","max_value","max_value","max_value","max_value",
"pop_front","pop_front","max_value","max_value",
"pop_front","push_back","push_back",
"pop_front","pop_front",
"max_value","max_value","push_back","max_value","max_value","max_value","max_value","push_back","max_value","push_back","max_value","max_value","push_back","push_back","max_value","push_back","max_value","pop_front","pop_front","max_value","pop_front","max_value","pop_front","pop_front","max_value","max_value","push_back","max_value","max_value","pop_front","pop_front","pop_front","max_value","max_value","max_value","max_value","push_back","max_value","pop_front","pop_front","pop_front","max_value","pop_front","max_value","max_value","max_value","max_value","push_back","max_value","push_back","push_back","max_value","push_back","pop_front","push_back","push_back","max_value","push_back","push_back","pop_front","push_back","max_value","push_back","push_back","max_value"]
[[],[],[19],[],[],[798],[],[97],[],[120],[],[],[341],[],[],[],[389],[],[],[],[597],[],[],[],[],[],[],[],[],[],[],[787],[348],[],[],[],[],[392],[],[],[],[],[138],[],[705],[],[],[275],[936],[],[321],[],[],[],[],[],[],[],[],[],[],[102],[],[],[],[],[],[],[],[],[],[131],[],[],[],[],[],[],[],[],[],[],[129],[],[129],[997],[],[729],[],[504],[490],[],[752],[269],[],[388],[],[74],[685],[]]
*/

void test2() {
    MaxQueue* obj = new MaxQueue();
    cout << obj->pop_front() << endl; 
    obj->push_back(19);
    cout << obj->max_value() << endl;   //19
    cout << obj->max_value() << endl;   //19
    obj->push_back(798);                //19 798
    cout << obj->max_value() << endl;   //798 
    obj->push_back(97);                 //19 798 97
    cout << obj->max_value() << endl;   //798 
    obj->push_back(120);                //19 798 97 120
    cout << obj->max_value() << endl;   //798
    cout << obj->max_value() << endl;   //798
    obj->push_back(341);                //19 798 97 120 341
    cout << obj->max_value() << endl;   //798
    cout << obj->pop_front() << endl;   //798 97 120 341
    cout << obj->pop_front() << endl;   //97 120 341
    obj->push_back(389);                //97 120 341 389
    cout << obj->pop_front() << endl;   //120 341 389
    cout << obj->max_value() << endl;   //389
    cout << obj->max_value() << endl;   //389
    obj->push_back(597);                //120 341 389 597
    cout << obj->pop_front() << endl;   //341 389 597
    cout << obj->max_value() << endl;   //597
    cout << obj->max_value() << endl;   //597
    cout << obj->max_value() << endl;   //597
    cout << obj->max_value() << endl;   //597
    cout << obj->pop_front() << endl;   //389 597
    cout << obj->pop_front() << endl;   //597
    cout << obj->max_value() << endl;   //597
    cout << obj->max_value() << endl;   //597
    cout << obj->pop_front() << endl;   //-1
    obj->push_back(787);                //787
    obj->push_back(348);                //787 348
    cout << obj->pop_front() << endl;   //348
    cout << obj->pop_front() << endl;   //-1
    cout << obj->max_value() << endl;   //-1
    cout << obj->max_value() << endl;   //-1

}

void test1() {
  MaxQueue* obj = new MaxQueue();
  int param_1 = obj->max_value();
  obj->push_back(871);
//   obj->push_back(646);
  cout << obj->max_value() << endl;
//   int param_3 = obj->pop_front();
  cout << obj->pop_front() << endl; 
  cout << obj->max_value() << endl;
  obj->push_back(889);
  cout << obj->max_value() << endl;
}