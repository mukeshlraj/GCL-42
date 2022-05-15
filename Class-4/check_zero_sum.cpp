#include<iostream>
#include<vector>
using namespace std;

bool check_sum(vector<int> arr) {
    unordered_map<int, bool> pref_sum;
    int curr_sum = 0;

    pref_sum[0] = true;

    for (int i = 0; i < arr.size(); ++i) {
        curr_sum += arr[i];

        // if the current_sum has previously been inserted in the map
        if (pref_sum.find(curr_sum) != pref_sum.end()) {
            return true;
        }

        pref_sum[curr_sum] = true;
    }
    return false;
}

int main() {

}