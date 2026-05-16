/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string par = "()(((()))())";
    stack<char>stk;
    for (int i=0; i<par.size(); i++)
    {
        if(par[i] == '(')
        {
            stk.push('(');
        }
        else
        {
            stk.pop();
        }
    }
    if(stk.empty())
    {
        cout<<"Valid parenthesis"<<endl;
    }
    else
    {
        cout<<"Invalid parenthesis"<<endl;
    }
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
        cout << "overflow\n";
    else
        stk[++top] = x;
}

char pop()
{
    if (top == -1)
        return '\0';
    else
        return stk[top--];
}

bool isEmpty()
{
    return (top == -1);
}

bool isValid(string str)
{
    for (char ch : str)
    {
        // opening brackets
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else
        {
            // if stack empty → invalid
            if (isEmpty())
                return false;

            char topChar = pop();

            // check matching
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '['))
            {
                return false;
            }
        }
    }

    // if stack empty → valid
    return isEmpty();
}

int main()
{
    string s1 = "()[]{}";
    string s2 = "(]";

    cout << (isValid(s1) ? "True" : "False") << endl;
    cout << (isValid(s2) ? "True" : "False") << endl;
}
