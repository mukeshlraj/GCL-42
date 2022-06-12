#include<iostream>
#include<vector>
using namespace std;

class Queue {
    stack<int> s1;
    stack<int> s2;

public:
    // TC : O(1)
    void queue_push(int x) {
        s1.push(x);
    }

    int queue_pop() {

        if (s1.empty()) {
            cout<<"Performing pop on empty queue";
            return -1;
        }

        // Empty s1 to s2
        while (!s1.empty()) {
            s2.push(s1.pop());
        }

        int answer = s2.pop();

        // Empty s2 to s1
        while(!s2.empty()) {
            s1.push(s2.pop());
        }
        return answer;
    }
};