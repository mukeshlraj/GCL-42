#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs_util(vector<vector<int>> &adj, int source, vector<bool> &vis, vector<int> &res) {
    queue<int> q;
    q.push(source);

    vis[source] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        res.push_back(current);

        for (int j : adj[current]) {
            if (!vis[j]) {
                vis[j] = true;
                q.push(j);
            }
        }
    }
}

vector<int> bfs(vector<vector<int>> adj) {
    int n = adj.size();
    vector<bool> vis(n, false);

    vector<int> res;

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            bfs_util(adj, i, vis, res);
        }
    }

    return res;
}

int main() {
    vector<int> res = bfs({{1,2},{0,3},{0,3,4},{1,2,4},{2,3}});

    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<" ";
    }
}