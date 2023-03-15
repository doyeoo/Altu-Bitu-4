#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    stack<int> s;

    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    for(int i=1; i<=n; i++) {
        if(!s.empty()) {
            if(s.top()<nums[i]) {
                while(nums[i]>0) {
                    s.push(nums[i]);
                    nums[i]--;
                }
            } else if(s.top()>nums[i]) {

            }
        } else {
            s.push(i);
        }
        cout << s.top() << endl;
    }

    return 0;
}