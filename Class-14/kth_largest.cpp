#include<iostream>
#include<queue>
#include<vector>
using namespace std;


// TC : O(n * log(k))
// Aux Space : O(k)

int kth_largest(vector<int> arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    // TC : O(k*log(k))
    for (int i = 0; i < k; ++i) {
        pq.push(arr[i]);
    }

    // TC : O((n - k) * log(k))
    for(int i=k; i<arr.size(); i++) {
        if (arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int kth_largest_2(vector<int> arr, int k) {
    priority_queue<int> pq;

    for (int i = 0; i < k; ++i) {
        pq.push(-arr[i]);
    }

    for(int i=k; i<arr.size(); i++) {
        if (arr[i] > -pq.top()) {
            pq.pop();
            pq.push(-arr[i]);
        }
    }

    return -pq.top();
}