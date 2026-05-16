#include<bits/stdc++.h>
using namespace std;

#define n 100

int stk[n];
int top = -1;

void push(int x)
{
    stk[++top] = x;
}

int pop()
{
    return stk[top--];
}

int evaluate(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == ' ') continue;

        // operand
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            int b = pop();
            int a = pop();

            if (ch == '+') push(a + b);
            else if (ch == '-') push(a - b);
            else if (ch == '*') push(a * b);
            else if (ch == '/') push(a / b);
        }
    }

    return pop();
}

int main()
{
    string s = "3 5 2 * +";

    cout << evaluate(s) << endl;
}