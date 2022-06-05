#include<iostream>
using namespace std;

vector<int> stack;
int top = -1;
int size = 10;

void push(int x) {
    if (top == size - 1)
        cout<<"stack overflow";

    else {
        top++;
        stack[top] = x;
    }
}

int pop() {
    int x;
    if (top == -1) {
        cout<<"stack underflow";
        return -1;
    } else {
        x = stack[top];

    }
    return x;
}