#include<vector>
#include<iostream>
using namespace std;

int max_element_range(vector<int> L, vector<int> R) {
    int n = L.size();
    int max_range = R[0];

    for(int i=1; i<n; i++) {
        max_range = max(max_range, R[i]);
    }

    vector<int> cum_freq(max_range + 2);

    // constructs freq table
    for(int i=0; i<n; i++) {
        cum_freq[L[i]]++;
        cum_freq[R[i] + 1]--;
    }

    // converts your freq table to prefix sum
    for (int i = 1; i < cum_freq.size(); i++)
    {
        cum_freq[i] = cum_freq[i-1] + cum_freq[i]; 
    }

    // find the smallest element with max freq
    int result = 0;
    for (int i = 0; i < cum_freq.size(); i++)
    {
        if (cum_freq[i] > cum_freq[result])
        {
            result=i;
        }
    }
    return result;
}