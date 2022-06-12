#include<iostream>
#include<vector>
using namespace std;

string largestString(string x, int k) {
    string answer = "";
    stack<char> temp;
    char temp1;
    temp.push(x[0]);

    for (int i = 1; i < x.length(); ++i) {
        temp1 = temp.top();
        if (x[i] > temp1 && k > 0) {
            temp.pop();
            k--;
        }
        temp.push(x[i]);
    }

    while (k--) {
        temp.pop();
    }

    // reverse the stack and make the answer string

    return answer;
}