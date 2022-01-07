#include<queue>
#include<iostream>
using namespace std;

class RecentCounter {
public:
    RecentCounter() {
        while(!q.empty()) {
            q.pop();
        }
    }
    
    int ping(int t) {
        q.push(t);
        while (q.front() + 3000 < t) {
            q.pop();
        }
        return q.size();
    }
private:
    queue<int> q;
};


int main() {
    RecentCounter* obj = new RecentCounter();
    cout << obj->ping(1) << endl;
    cout << obj->ping(100) << endl;
    cout << obj->ping(3001) << endl;
    cout << obj->ping(3002) << endl;
    return 0;
}