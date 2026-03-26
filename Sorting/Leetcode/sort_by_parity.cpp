#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int left = 0, right = n - 1;
    while(left < right)
    {
        if(arr[left] % 2 == 0)
            left++;
        else if(arr[right] % 2 == 1)
            right--;
        else
            swap(arr[left], arr[right]);
    }

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
