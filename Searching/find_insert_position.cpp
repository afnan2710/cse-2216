#include<bits/stdc++.h>
using namespace std;

int searchInsertPosition(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    int ans = n; // default insert at end

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] > target)
        {
            ans = mid; // possible position
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int n, target;
        cin >> n >> target;

        int arr[10005];

        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int result = searchInsertPosition(arr, n, target);

        cout << result << endl;
    }
}
