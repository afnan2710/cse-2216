#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(int arr[], int n, int x)
{
    int low = 0, high = n - 1, loc = -1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == x)
        {
            loc = mid;
            high = mid - 1;
        }
        else if(arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return loc;
}

int lastOccurrence(int arr[], int n, int x)
{
    int low = 0, high = n - 1, loc = -1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == x)
        {
            loc = mid;
            low = mid + 1;
        }
        else if(arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return loc;
}

int main()
{
    int n;
    cout << "Enter the size of sorted array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of sorted array: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int x;
    cout << "Enter the search key value: ";
    cin >> x;

    int first = firstOccurrence(arr, n, x);
    int last  = lastOccurrence(arr, n, x);

    if(first == -1)
        cout << "Element " << x << " not found! Output: -1 -1" << endl;
    else
    {
        cout << "First occurrence of " << x << " is at index: " << first << endl;
        cout << "Last  occurrence of " << x << " is at index: " << last  << endl;
    }

    return 0;
}
