#include <bits/stdc++.h>
using namespace std;

int searchRotated(int arr[], int n, int target) {
    int low = 0, high = n-1;
    int ans = -1;

    while (low <= high) {
        int mid = (low+high)/2;

        if (arr[mid] == target) {
            ans = mid;
            high = mid-1;
        }
        else if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
        }
        else if (arr[low] <= arr[mid]) {
            if (target >= arr[low] && target < arr[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        else {
            if (target > arr[mid] && target <= arr[high])
                low = mid+1;
            else
                high = mid-1;
        }
    }
    return ans;
}

int main()
{
    int a1[] = {2, 5, 6, 0, 0, 1, 2};
    cout<<searchRotated(a1, 7, 0)<<endl;
    int a2[] = {2, 2, 2, 3, 2, 2};
    cout<<searchRotated(a2, 6, 3)<<endl;
}

/*
step 1: apply binary search
step 2: if found, store index and move left (for smallest index)
step 3: handle duplicate case (low==mid==high)
step 4: identify sorted half (left or right)
step 5: move accordingly
*/
