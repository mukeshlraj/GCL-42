#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo;

// TC : O(n * m)
// Aux Space : O(n * m)
int get_min_helper(string &A, string &B, int i, int j) {
    // base cases
    if (i == A.length()) { // insert all the remaining char present in B
        return B.length() - j;
    }

    if (j == B.length()) { // delete all the remaining char in A
        return A.length() - i;
    }

    if (memo[i][j] != -1)
        return memo[i][j];

    if (A[i] == B[j]) {
        return get_min_helper(A, B, i+1, j+1);
    }

    // CASE 1 : Try insertion
    int result = 1 + get_min_helper(A, B, i, j+1);

    // CASE 2 : Try deletion
    result = min(result, 1 + get_min_helper(A, B, i+1, j));

    // CASE 3 : Try replace
    result = min(result, 1 + get_min_helper(A, B, i+1, j+1));

    return memo[i][j] = result;
}

int get_min(string A, string B) {

    int n = A.length();
    int m = B.length();
    memo = vector<vector<int>> (n, vector<int> (m, -1));
    return get_min_helper(A, B, 0, 0);
}

int main() {
    cout << get_min("abad", "abac") << endl;
    cout << get_min("Anshuman", "Antihuman") << endl;
}