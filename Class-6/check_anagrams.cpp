#include<iostream>
using namespace std;

bool anagram(string s1, string s2) {
    int n = s1.length();
    if ((int) s2.length != n) {
        return false;
    }

    vector<int> char_freq(26,0);

    // store the frequency of each character in both the strings
    for (int i = 0; i < n; ++i) {
        char_freq[s1[i] - 'a']++;
        char_freq[s2[i] - 'a']--;
    }

    // compare the freq of each char
    for (int i = 0; i < 26; ++i) {
        if (char_freq[i] != 0)
            return false;
    }
    return true;
}
