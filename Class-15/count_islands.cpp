#include <iostream>
#include <vector>
using namespace std;

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

bool is_valid(int i, int j, vector<vector<int>> &arr) {
    return (i>=0 and i<arr.size() and j>=0 and j<arr[i].size() and arr[i][j]==1);
}

void dfs(vector<vector<int>> &arr, int i, int j) {

    if (arr[i][j] == 0)
        return;

    arr[i][j] = 0;

    for (int k = 0; k < 8; ++k) {
        if (is_valid(i+dx[k], j+dy[k], arr)) {
            dfs(arr, i+dx[k], j+dy[k]);
        }
    }

}

int count_islands(vector<vector<int>> arr) {
    int n = arr.size();
    int m = arr[0].size();

    int count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == 1) {
                count++;
                dfs(arr, i ,j);
            }
        }
    }

    return count;
}

int main() {
    cout<<count_islands({{1,0,0,1,0},
                         {1,1,0,0,0},
                         {0,0,1,1,1},
                         {0,0,0,0,0},
                         {0,1,1,0,0}});
}