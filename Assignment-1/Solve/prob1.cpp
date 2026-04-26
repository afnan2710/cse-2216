#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int kthSmallest(int a[], int n, int k) {
    int picked[50];
    int pSize = 0;

    for (int i=0; i<n; i++) {
        if ((i+1)%2 == 1) {
            picked[pSize] = a[i];
            pSize++;
        }
    }
    bubbleSort(picked, pSize);

    int uniquevalues[50];
    int uSize = 0;
    for (int i=0; i<pSize; i++) {
        if (i==0 || picked[i] != picked[i-1]) {
            uniquevalues[uSize] = picked[i];
            uSize++;
        }
    }

    if (k>uSize)
        return -1;
    return uniquevalues[k-1];
}

int main()
{
    int a1[] = {6, 5, 1, 3, 4, 1, 8};
    cout<<kthSmallest(a1, 7, 2)<<endl;
    int a2[] = {7, 9, 1, 8, 2};
    cout<<kthSmallest(a2, 5, 4)<<endl;
}

/*
step 1: take the only odd indices from the total array
step 2: then applies bubble sort
step 3: removes duplicates
step 4: return k-th minimum value
*/
