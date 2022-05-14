#include<iostream>
#include<vector>

using namespace std;

int sorted_rotated_search(vector<int> arr, int key) {
    int n = arr.size();

    int low = 0, high = n-1;
    while (low<=high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        // check which half is sorted
        if (arr[mid] > arr[low]) { //left half is sorted
            if(key >= arr[low] and key < arr[mid]) { //key is in sorted half
                high = mid - 1;
            } else { // it is in right side
                low = mid + 1;
            }
        } else { // right half is sorted
            if (key > arr[mid] and key<= arr[high]) { // key is in sorted half
                low = mid + 1;
            } else { // it is in left side
                high = mid -1;
            }
        }
    }
    return -1;
}