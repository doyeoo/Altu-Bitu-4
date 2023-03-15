#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n, num;
    string inst;

    cin >> n;

    deque<int> d;

    for(int i=0; i<n; i++) {
        cin >> inst;

        if(inst=="push_front") {
            cin >> num;
            d.push_front(num);
        } else if(inst=="push_back") {
            cin >> num;
            d.push_back(num);
        } else if(inst=="pop_front") {
            if(d.empty()) {
                cout << -1 << endl;
            } else {
                cout << d.front() << endl;
                d.pop_front();
            }
        } else if(inst=="pop_back") {
            if(d.empty()) {
                cout << -1 << endl;
            } else {
                cout << d.back() << endl;
                d.pop_back();
            }
        } else if(inst=="size") {
            cout << d.size() << endl;
        } else if(inst=="empty") {
            cout << d.empty() << endl;
        } else if(inst=="front") {
            if(d.empty()) {
                cout << -1 << endl;
            } else {
                cout << d.front() << endl;
            }
        } else if(inst=="back") {
            if(d.empty()) {
                cout << -1 << endl;
            } else {
                cout << d.back() << endl;
            }
        }
    }
}