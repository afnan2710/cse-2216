/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "Hello World";
    stack<char>stk;
    for (int i=0; i<s.size(); i++)
    {
        stk.push(s[i]);
    }
    string rev;
    while(!stk.empty())
    {
        rev+=stk.top();
        stk.pop();
    }
    cout<<rev<<endl;
}
*/

#include <bits/stdc++.h>
using namespace std;

#define n 100
char stk[n];
int top = -1;

void push(char x)
{
    if (top == n - 1)
        cout << "overflow" << endl;
    else
        stk[++top] = x;
}

char pop()
{
    if (top == -1)
    {
        cout << "underflow" << endl;
        return '\0';
    }
    else
        return stk[top--];
}

bool isEmpty()
{
    return (top == -1);
}

int main()
{
    string str = "Hello World";
    string result = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            push(str[i]);  // push characters
        }
        else
        {
            // pop all characters for current word
            while (!isEmpty())
            {
                result += pop();
            }
            result += ' '; // keep space
        }
    }

    // last word
    while (!isEmpty())
    {
        result += pop();
    }

    cout << result << endl;
}
