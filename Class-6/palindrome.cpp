#include<iostream>
using namespace std;

bool is_alpha_numeric(char ch) {
    return ((ch>= '0' and ch <= '9') or (ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z'));
}

bool are_equal(char ch1, char ch2) {
    // if ch1 == ch2 return true;
    // if ch1 is uppercase and ch2 is lowercase => convert and compare and return
    // if ch1 is lowercase and ch2 is uppercase => convert and compare and return

    return ((ch1==ch2) or ((ch1 - 'a' + 'A') == ch2) or ((ch1 - 'A' + 'a') == ch2));
 }

bool check_palindrome(string s) {
    int n = s.length();

    int i = 0, j = n-1;

    while (i<j) {
        if (!is_alpha_numeric(s[i])) {
            i++;
        } else if(!is_alpha_numeric(s[j])) {
            j--;
        } else {
            // Check both char are equal, also make sure the cases are ignored
            if (are_equal(s[i], s[j])) {
                i++;
                j--;
            } else {
                return false;
            }
        }
    }
    return true;
}