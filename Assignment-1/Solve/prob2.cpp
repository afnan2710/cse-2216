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

int longestConsecutive(int a[], int n) {
    int neg[50], pos[50];
    int ni=0, pi=0;

    for (int i=0; i<n; i++) {
        if (a[i]<0) {
            neg[ni++] = a[i];
        } else {
            pos[pi++] = a[i];
        }
    }

    bubbleSort(neg, ni);
    bubbleSort(pos, pi);

    int sortedArr[50];
    int idx = 0;

    for (int i=0; i<ni; i++) {
        sortedArr[idx++] = neg[i];
    }
    for (int i=0; i<pi; i++) {
        sortedArr[idx++] = pos[i];
    }

    int maxLen = 1, currLen = 1;

    for (int i=1; i<n; i++) {
        if (sortedArr[i] == sortedArr[i-1]+1) {
            currLen++;
            if (currLen > maxLen)
                maxLen = currLen;
        }
        else if (sortedArr[i] != sortedArr[i-1]) {
            currLen = 1;
        }
    }
    return maxLen;
}

int main()
{
    int a1[] = {3, -2, -5, 0, 4, -1, 2};
    cout<<longestConsecutive(a1, 7)<<endl;
    int a2[] = {1, -3, -2, 5};
    cout<<longestConsecutive(a2, 4)<<endl;
}

/*
step 1: separate negative and positive numbers into two array
step 2: then apply bubble sort individually
step 3: merge both sorted arrays (negative then positive)
step 4: traverse and count longest consecutive sequence
*/
