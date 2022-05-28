#include<iostream>
using namespace std;

vector<int> fact;

void pre(int n) {
    fact = vector<int> (n);
    fact[0] = 1;
    fact[1] = 1;

    for (int i = 2; i < n; ++i) {
        fact[i] = (fact[i-1] * i);
    }
}


int lexicographic_rank(string s) {
    int n = s.length();
    pre(n);

    string s_sorted = s;
    sort(s_sorted.begin(), s_sorted.end());

    int result = 0;

    for (int i = 0; i < n; ++i) {
        int smaller_count = 0;

        // number of smaller characters than s[i] = number of non-hashed characters occuring before
        // s[i]
        for (int j = 0; j < n; ++j) {
            if (s_sorted[j] == s[i]) {
                s_sorted[j] = '#';
                break;
            }

            if (s_sorted[j] != '#')
                smaller_count++;
        }
        result = result + (smaller_count * fact[n-i-1]);
    }
    return result + 1;
}