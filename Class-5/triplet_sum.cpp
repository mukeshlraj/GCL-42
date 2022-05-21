#include<vector>
#include<iostream>
using namespace std;

bool triplet_sum(vector<int> arr, int target) {
    sort(arr.begin(), arr.end());

    int n = arr.size();

    for (int i = 0; i < n-2; i++)
    {
        // two pointer approach to check if pair with sum target-arr[i] is present
        int s = i+1, e=n-1;
        while (s<e)
        {
            if (arr[s]+arr[e] == (target-arr[i]))
            {
                return true;
            }
            if (arr[s] + arr[e] > (target-arr[i]))
            {
                e--;
            }
            else
            {
                s++;
            }
        }
    }
    return false;
}