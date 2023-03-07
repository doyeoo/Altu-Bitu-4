#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, k;
    int cnt=1;
    queue<int> q;
    vector<int> result;

    cin >> n >> k;

    for(int i=1; i<=n; i++) {
        q.push(i);
    }

    while(!q.empty()) {
        if(cnt==k) {
            result.push_back(q.front());
            q.pop();
            cnt=1;
        } else {
            q.push(q.front());
            q.pop();
            cnt++;
        }
    }

    cout << "<" << result[0];
    for(int i=1; i<n; i++) {
        cout << ", " << result[i];
    }
    cout << ">";

    return 0;
}