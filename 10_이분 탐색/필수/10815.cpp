#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearch(int n, int key, vector<int> &nums) {
    int left=0;
    int right=n-1;

    while(left<=right) {
        int mid=(left+right)/2;
        if(nums[mid]==key) {
            return 1;
        }
        else if(nums[mid]<key) {
            left=mid+1;
        }
        else if(nums[mid]>key) {
            right=mid-1;
        }
    }

    return 0;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n, m, key;

    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    //이진탐색은 정렬된 배열에서!!
    sort(nums.begin(), nums.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> key;
        cout << binarySearch(n, key, nums) << " ";
    }

    return 0;
}