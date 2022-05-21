#include<vector>
#include<iostream>
using namespace std;

bool matrix_search(vector<vector<int> > arr, int x, int n, int m) {
        int i = 0, j = m-1;

        while (i<n && j>=0) {
            if (arr[i][j] == x) {
                return true;
            }
            if (arr[i][j] > x) {
                j--;
            }
            else {
                i++;
            }
        }
        return false;
}

int main() {
    cout<<matrix_search({{3,30,38},{36,43,60},{40,51,69} }, 40, 3, 3);
}