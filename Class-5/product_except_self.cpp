#include<vector>
#include<iostream>
using namespace std;

vector<int> product_except_self(vector<int> arr) {
    int n = arr.size();

    vector<int> left_prod(n);
    vector<int> right_prod(n);

    left_prod[0] = 1;
    for (int i = 1; i < n; i++)
    {
        left_prod[i] = left_prod[i-1] * arr[i-1];
    }
    
    right_prod[n-1] = 1;
    for (int i = n-2; i >= 0; i--)
    {
        right_prod[i] = right_prod[i+1] * arr[i+1];
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
       ans[i] = left_prod[i] * right_prod[i];
    }
    return ans;
}