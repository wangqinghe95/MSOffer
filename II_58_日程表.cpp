#include<iostream>
#include<map>
using namespace std;

// map
// lower_bound：找到map中第一个大于等于start的返回迭代器
// upper_bound：找到map中第一个大于start的迭代器返回迭代器
class MyCalendar {
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        auto it = calendar.lower_bound(start);
        // if (it != calendar.end()) {
        //     cout << "it is not calender end" << endl;
        // }
        if (it != calendar.end() && it->first < end) {
            return false;
        }
        // if (it != calendar.begin()) {
        //     cout << "it is not calendar begin" << endl;
        //     cout << it->first << endl;
        //     cout << calendar.begin()->first << endl;
        // }
        if (it != calendar.begin() && (--it)->second > start) {
            return false;
        }

        calendar[start] = end;
        return true;
    }
private:
    map<int,int> calendar;
};

int main()
{
    MyCalendar calendar;
    calendar.book(10,15);
    calendar.book(20,25);
    calendar.book(15,20);
    calendar.book(20,30);
    return 0;
}