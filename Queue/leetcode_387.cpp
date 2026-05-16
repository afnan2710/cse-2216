#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    map<char, int>mp;
    queue<char>q;
    for(int i=0; i<s.size(); i++)
    {
        mp[s[i]]++;
        if(mp[s[i]]==1)
        {
            q.push(s[i]);
        }
    }
    while(!q.empty())
    {
        if(mp[q.front()]>1)
            q.pop();
        else
            break;
    }
    if(q.empty())
    {
        cout<<"-1"<<endl;
    }
    else
        cout<<q.front()<<endl;
}


/*

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    unordered_map<char,int>mp;
    queue<int>q;
    for(int i=0;i<s.size();i++)
    {
        mp[s[i]]++;
        if(mp[s[i]]==1)
            q.push(i);
    }
    while(!q.empty())
    {
        if(mp[s[q.front()]]>1)
            q.pop();
        else
            break;
    }
    if(q.empty())
        cout<<"-1"<<endl;
    else
        cout<<q.front()<<endl;
}

*/