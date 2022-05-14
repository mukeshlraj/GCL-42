#include<iostream>
#include<vector>
using namespace std;

// TC : O(n)
// Aux Space : O(1)
int kadane_algo(vector<int> arr) {
    int n = arr.size();

    int max_ending_here = arr[0];
    int result = arr[0];

    for(int i=1; i<n; i++) {
        int curr_max;
        if (max_ending_here > 0) {
            curr_max = max_ending_here + arr[i];
        } else {
            curr_max = arr[i];
        }

        result = max(result, curr_max);
        max_ending_here = curr_max;
    }
    return result;
}

int main() {
    cout<<kadane_algo({-5,1,3,-7,5,2})<<endl;
}