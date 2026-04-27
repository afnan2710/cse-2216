#include <bits/stdc++.h>
using namespace std;

int searchNearlySorted(int arr[], int n, int target) {
    int low = 0, high = n-1;

    while (low <= high) {
        int mid = (low+high)/2;

        if (arr[mid] == target)
            return mid;

        if (mid-1 >= low && arr[mid-1] == target)
            return mid-1;

        if (mid+1 <= high && arr[mid+1] == target)
            return mid+1;

        if (target < arr[mid])
            high = mid-2;
        else
            low = mid+2;
    }
    return -1;
}

int main()
{
    int a1[] = {5, 10, 30, 20, 40};
    cout<<searchNearlySorted(a1, 5, 20)<<endl;
    int a2[] = {3, 2, 1, 4, 5};
    cout<<searchNearlySorted(a2, 5, 1)<<endl;
}

/*
step 1: apply binary search
step 2: check mid, mid-1, mid+1
step 3: if not found, move left/right by skipping 2 elements
step 4: return index if found, otherwise -1
*/
