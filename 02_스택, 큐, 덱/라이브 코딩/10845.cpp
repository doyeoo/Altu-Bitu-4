#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num;
    string inst;

    queue<int> q;

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> inst;

        if(inst=="push") {
            cin >> num;
            q.push(num);
        } else if(inst=="pop") {
            if(q.empty()) {
                cout << -1 << endl;
            } else {
                cout << q.front() << endl;
                q.pop();
            }
        } else if(inst=="size") {
            cout << q.size() << endl;
        } else if(inst=="empty") {
            cout << q.empty() << endl;
        } else if(inst=="front") {
            if(q.empty()) {
                cout << -1 << endl;
            } else {
                cout << q.front() << endl;
            }
        } else if(inst=="back") {
            if(q.empty()) {
                cout << -1 << endl;
            } else {
                cout << q.back() << endl;
            }
        }
    }

    return 0;
}
