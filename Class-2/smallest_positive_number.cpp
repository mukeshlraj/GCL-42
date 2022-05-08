#include<iostream>
#include<vector>
using namespace std;

int smallest_positive(vector<int> arr) {
    int n = arr.size();

    // STEP-1: Replace the non-positive numbers.
    for(int i = 0; i<n; i++) {
        if (arr[i]<=0)
            arr[i] = n+1;
    }

    // STEP-2: For any valid element make its bucket negative
    for (int i=0; i<n; i++) {
        int element = abs(arr[i]);
        if (element >=1 and element <=n and arr[element - 1] > 0) {
            arr[element-1] *= -1;
        }
    }

    // STEP-3: Iterate and return the smallest number
    for(int i=0; i<n; i++) {
        if (arr[i] > 0) {
            return i+1;
        }
    }
    return n+1;
    }

    int main() {
    cout<<smallest_positive({1,2,3,4,5})<<endl;
    cout<<smallest_positive({1,1})<<endl;
}
