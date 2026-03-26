#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test_case;
    cout<<"Enter number of test cases: ";
    cin>>test_case;
    while(test_case--)
    {
        int num_of_post;
        cout<<"Enter number of posts: ";
        cin>>num_of_post;
        int like[num_of_post], comment[num_of_post];
        cout<<"Enter likes: ";
        for(int i=0; i<num_of_post; i++)
            cin >> like[i];
        cout<<"Enter comments: ";
        for(int i=0; i<num_of_post; i++)
            cin>>comment[i];

        int best=0;
        for(int i=1; i<num_of_post; i++)
        {
            if(like[i]>like[best] || (like[i]==like[best] && comment[i]>comment[best]))
                best = i;
        }
        cout << "Most popular post index: " << best + 1 << "\n";
    }
    return 0;
}
