#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> merge_n_sorted(vector<vector<int>> arr) {
    int n = arr.size();

    priority_queue<pair<int, pair<int, int>>> pq;

    for (int i = 0; i < n; ++i) {
        pq.push({-arr[i][0], {i,0}});
    }

    vector<int> result;
    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        int element = -current.first;
        int i = current.second.first;
        int j = current.second.second;

        result.push_back(element);
        if (j+1 < n)
            pq.push({-arr[i][j+1], {i,j+1}});
    }

    return result;
}