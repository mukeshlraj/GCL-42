#include <iostream>
#include <vector>
using namespace std;

void add_edge_directed(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
}

void print_adj_list(vector<vector<int>> &adj) {

    for(int i=0; i<adj.size(); i++) {
        cout<<i<<": ";
        for (int j : adj[i]) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int V = 4;
    vector<vector<int>> adj(4);

    add_edge_directed(adj, 0, 2);
    add_edge_directed(adj, 0, 3);
    add_edge_directed(adj, 1, 2);
    add_edge_directed(adj, 1, 3);
    add_edge_directed(adj, 2, 0);
    add_edge_directed(adj, 2, 1);
    add_edge_directed(adj, 2, 3);
    add_edge_directed(adj, 3, 0);
    add_edge_directed(adj, 3, 1);
    add_edge_directed(adj, 3, 2);

    print_adj_list(adj);
}