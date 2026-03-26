#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int expected = n * (n + 1) / 2;
    int actual = 0;
    for(int i = 0; i < n; i++)
        actual += arr[i];

    cout << expected - actual;
}
