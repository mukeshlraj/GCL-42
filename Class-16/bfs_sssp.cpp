#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> bfs_sssp(vector<vector<int>> adj, int source) {

    int n = adj.size();
    vector<int> dist(n, INT_MAX);

    dist[source] = 0;

    queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int j : adj[current]) {
            if (dist[j] > dist[current] + 1) {
                dist[j] = dist[current] + 1;
                q.push(j);
            }
        }
    }

    return dist;
}

int main() {
    vector<int> dist = bfs_sssp({{1,2},{0,3},{0,3,4},{1,2,4},{2,3}}, 0);

    for (int i = 0; i < dist.size(); ++i) {
        cout<<"Distance to "<<i<<": "<<dist[i]<<endl;
    }
}