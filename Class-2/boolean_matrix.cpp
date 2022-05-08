#include<iostream>
#include<vector>
using namespace std;

// TC : O(m*n)
// Aux Space : O(1)
vector<vector<int>> set_matrix_zeros(vector<vector<int>> arr) {
    int n = arr.size();
    int m = arr[0].size();

    // STEP-1: Check if the 0th row and the 0th column contains any zero.
    bool zero_row = false;
    bool zero_col = false;

    for(int i = 0; i<m; i++) {
        if(arr[0][i] == 0) {
            zero_row = true;
            break;
        }
    }

    for(int i = 0; i<n; i++) {
        if(arr[i][0] == 0) {
            zero_col = true;
            break;
        }
    }

    // STEP-2 : Traverse through inner matrix keeping 0th row and 0th column as buckets
    for(i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if (arr[i][j] == 0) {
                arr[0][j] = 0;
                arr[i][0] = 0;
            }
        }
    }

    // STEP-3 : Update the inner matrix according to bucket values
    for(i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if (arr[i][0] == 0 or arr[0][j] == 0) {
                arr[i][j] = 0;
            }
        }
    }

    // STEP-4 : Make updates according to var zero_row and zero_col
    if (zero_row) {
        for(int j=0; j<m; j++) {
            arr[0][j] = 0;
        }
    }
    if (zero_col) {
        for(int j=0; j<m; j++) {
            arr[j][0] = 0;
        }
    }
    return arr;
}