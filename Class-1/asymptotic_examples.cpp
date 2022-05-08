swap(x,y)
{
    t = x;
    x = y;
    y = t;
}

sum(Arr, n) {
    s = 0;
    for(i=0; i<n ; i++) // 1 + (n+1) + n = 2n+2
    s = s+ Arr[i]; // n times

    return s;
}

add(A,B,m,n) {
    for(i=0;i<n;i++) { // 2n+2
        for(j=0;j<n;j++){ // (2n+2) * n
            c[i][j] = A[i][j] + B[i][j] // n*n
        }
    }
}

/*
TC : O (m + n)
Auxiliary Space : O(1)
Space Complexity : O( m + n)
*/
int count=0;
for (int i=0; i<A.size(); i++)
cout<<A[i];

for(int j=0; j<B.size(); j++)
cout<<B[i];

// ---------------------------------------------

/*
TC : O (m*n)
Auxiliary Space : O(1)
Space Complexity : O(m + n)
*/
int i,j;
for ( i = 0; i < A.size(); i++) {
    for ( j = 0; j < B.size(); j++) {
        cout << A[i] + B[j] << endl;
    }
}

// ---------------------------------------------

/*
TC : O(n)
Auxiliary Space : O(n) // temp(n) + some variables = n + 1 = O (n)
Space Complexity : O(n + n + 1) = O(n)
*/
void copy(int arr[], int n) {
    int temp[n];
    for(i=0; i<n; i++) {
        temp[i] = arr[i];
    }
    print(temp);
}

// ---------------------------------------------

/*
TC : O(m * n^2)
Auxiliary Space : O(1)
Space Complexity : O(m)
*/

// s.length() = m
void func(int n, string s) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << s << endl;
        }
    }
}

// ---------------------------------------------

/*
TC : O(n^2)
Auxiliary Space : O(1)
Space Complexity : O(n)
*/

void func(int A[], int B[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if(A[i] > B[j])
            swap(A[i],B[j])
        }
    }
}

// ---------------------------------------------