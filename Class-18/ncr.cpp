#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo;

int p = 1e9 + 7;

int ncr_helper(int n, int r) {

    if (r==0 or n==r)
        return 1;

    if (n < r)
        return 0;

    if (memo[n][r] != -1) {
        return memo[n][r];
    }

    return memo[n][r] = ((ncr_helper(n-1, r-1) % p + ncr_helper(n-1, r) % p)) % p;
}

int nCr(int n, int r) {
    memo = vector<vector<int>> (n+1, vector<int>(r+1, -1));
    return ncr_helper(n,r);
}

int main() {
    cout << nCr(3,2)<<endl;
    cout<< nCr(4,2)<<endl;
}