#include <bits/stdc++.h>
using namespace std;

int upperBound(int arr[], int n, int x)
{
    int low = 0, high = n - 1, ans = n;
    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] > x)    //for lower, insert an =
        {
            ans = mid;        // mid is a possible answer, search left for smaller index
            high = mid - 1;
        }
        else
        {
            low = mid + 1;    // arr[mid] <= x, search right
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int x;
    cin >> x;
    cout << upperBound(arr, n, x) << endl;
    return 0;
}
