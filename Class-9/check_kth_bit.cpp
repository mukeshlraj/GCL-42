#include<iostream>
using namespace std;

bool check_kth_bit(int n, int k) {
    int mask = (1<<k);
    if ((n & mask) !=0 ) {
        return true;
    }
    return false;
}
