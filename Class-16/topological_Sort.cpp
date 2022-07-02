#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>> &adj, int current, vector<bool> &vis, stack<int> &s) {

    if (vis[current])
        return;

    vis[current] = true;

    for (int j : adj[current]) {
        dfs(adj, j, vis, s);
    }

    s.push(current);
}

vector<int> topolical_sort(vector<vector<int>> adj) {
    int n = adj.size();
    vector<bool> vis(n,false);
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        if (!vis[i])
            dfs(adj, i, vis, s);
    }

    vector<int> result;

    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }

    return result;
}

int main() {
    vector<int> res = topolical_sort({{},{},{3},{1},{0,1},{2,0}});

    for (int i : res) {
        cout << i << " ";
    }
}