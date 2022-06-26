#include <iostream>
#include <vector>
using namespace std;

void dfs_helper(vector<vector<int>> &adj, int current, vector<bool> &visited) {

    if (visited[current])
        return;

    visited[current] = true;
    cout<<current<<" ";

    for(int neighbour : adj[current])
        dfs_helper(adj, neighbour, visited);
}

void dfs(vector<vector<int>> adj) {
    int V = adj.size();
    vector<bool> visited(V, false);


    int count = 0;
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            count++;
            dfs_helper(adj, i, visited);
        }
    }
    cout<<endl;
    cout<<"Connected components : "<<count<<endl;
}

int main() {
    dfs({{1,2,3},{4},{3},{4},{}});

    dfs({{1},{},{3},{}});
}