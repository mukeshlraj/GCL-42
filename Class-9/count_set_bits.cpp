#include<iostream>
using namespace std;

// TC : O(number of bits)
int count_set_bits(int n) {
    int cnt = 0;

    while (n != 0) {
        // if rightmost bit is set or not
        if ((n&1) != 0)
            cnt++;

        // Discard rightmost bit
        n = (n>>1);
    }

    return cnt;
}

// TC: O(number of set bits)
int count_set_bits_opt(int n) {
    int cnt = 0;

    while (n != 0) {
        n = (n & (n-1));
        cnt++;
    }

    return cnt;
}