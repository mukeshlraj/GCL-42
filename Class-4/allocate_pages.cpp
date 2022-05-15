#include<iostream>
#include<vector>
using namespace std;

bool is_possible(vector<int> A, int m, int mid) {
    int student_count = 1;
    int pages_count = A[0];

    for(int i=1; i<A.size(); i++) {
        // in this case, the current book can be allocated to the current student
        if (pages_count + A[i] <= mid) {
            pages_count = pages_count + A[i];
        } else { // in this case, the allocation for a new student will be started
            student_count++;
            pages_count = A[i];
        }
    }
    return (student_count<=m);
}

int allocate_books(vector<int> A, int m) {
    int n = A.size();

    // low = max value in array
    // high sum of array
    int low = A[0], high = A[0];
    for(int i=1; i<n ;i++) {
        low = max(low, A[i]);
        high = high + A[i];
    }
    int result = high;

    while (low<=high) {
        int mid = (low + high) / 2;

        // if it is possible to allocate books such that no student reads more than mid number of pages
        if (is_possible(A,m,mid)) {
            high = mid - 1;
            result = mid;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    cout<< allocate_books({10,20,10,30},2)<<endl;
    cout<<allocate_books({12,34,67,90},2)<<endl;
}