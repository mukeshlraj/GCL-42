#include <iostream>
#include <vector>

using namespace std;

bool detect_cycle_directed_util(vector<vector<int>> &adj, int current, vector<bool> &vis, vector<bool> &rec) {

    vis[current] = true;
    rec[current] = true;

    for (int j : adj[current]) {
        if (rec[j]) {
            return true;
        }

        if (detect_cycle_directed_util(adj, j, vis, rec)) {
            return true;
        }
    }

    rec[current] = false;

    return false;
}

bool detect_cycle_directed(vector<vector<int>> adj) {
    int n = adj.size();

    vector<bool> vis(n, false);
    vector<bool> rec(n, false);

    for (int i = 0; i < n; ++i) {
        if (!vis[i] and detect_cycle_directed_util(adj, i, vis, rec))
            return true;
    }
    return false;
}

int main () {

    cout<<detect_cycle_directed({{1},{2,3},{3},{}}) << endl;

    cout<<detect_cycle_directed({{},{0,2},{3},{1}}) << endl;
}