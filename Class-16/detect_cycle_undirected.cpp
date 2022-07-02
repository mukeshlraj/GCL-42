#include <iostream>
#include <vector>

using namespace std;

bool detect_cycle_util(vector<vector<int>> &ad, int current, int parent, vector<bool> &vis) {

    vis[current] = true;

    for(int j : ad[current]) {
        if (vis[j] and j != parent)
            return true;

        if (!vis[j] and detect_cycle_util(ad, j, current, vis))
            return true;
    }

    return false;
}

bool detect_cycle_undirected_graph(vector<vector<int>> ad) {
    int n = ad.size();
    vector<bool> vis(n, false);

    for (int i = 0; i < n; ++i) {
        if (!vis[i] and detect_cycle_util(ad, i, -1, vis)) {
            return true;
        }
    }

    return false;
}

int main() {
    cout<< detect_cycle_undirected_graph({{1},{0,2},{1,3},{2,4},{3}}) << endl;

    cout<< detect_cycle_undirected_graph({{1},{0,2,4},{1,3},{2,4},{1,3}}) << endl;

    cout<< detect_cycle_undirected_graph({{0}}) << endl;
}