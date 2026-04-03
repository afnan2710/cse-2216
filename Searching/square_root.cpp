#include <bits/stdc++.h>
using namespace std;

int squareRoot(int n)
{
    int low = 0, high = n;
    int ans = 0;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(mid * mid == n)
            return mid;
        else if(mid * mid < n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return ans;
}

int main()
{
    int n;
    cout<<"Enter number: ";
    cin>>n;
    cout<<"Square Root of "<<n<<" is: "<<squareRoot(n)<<endl;
    main();
}
