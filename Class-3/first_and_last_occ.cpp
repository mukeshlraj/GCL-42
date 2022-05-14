#include<iostream>
#include<vector>

using namespace std;

// TC : O(log (n))
int first_occurrence(vector<int> arr, int k) {
    int low = 0, high = (int) arr.size() - 1;
    int first = -1;

    while (low<=high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k) {
            first = mid;

            //if it is not the first occ, then the first will lie in the left
            if(arr[mid-1] == k)
            high = mid -1;
        } else if (arr[mid] > k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return first;
}

int last_occurrence(vector<int> arr, int k) {
    int low = 0, high = (int) arr.size() - 1;
    int last = -1;

    while (low<=high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k) {
            last = mid;

            //if it is not the last occ, then the last will lie in the right
            low = mid + 1;
        } else if (arr[mid] > k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return last;
}

int main() {}