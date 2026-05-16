#include<bits/stdc++.h>
using namespace std;

#define n 100

char stk[n];
int top = -1;

void push(char x)
{
    stk[++top] = x;
}

char pop()
{
    return stk[top--];
}

char peek()
{
    return stk[top];
}

bool isEmpty()
{
    return top == -1;
}

int precedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string s)
{
    string result = "";

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == ' ') continue;

        // operand
        if (isdigit(ch))
        {
            result += ch;
            result += ' ';
        }

        else if (ch == '(')
        {
            push(ch);
        }

        else if (ch == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                result += pop();
                result += ' ';
            }
            pop(); // remove '('
        }

        else // operator
        {
            while (!isEmpty() && precedence(peek()) >= precedence(ch))
            {
                result += pop();
                result += ' ';
            }
            push(ch);
        }
    }

    // remaining operators
    while (!isEmpty())
    {
        result += pop();
        result += ' ';
    }

    return result;
}

int main()
{
    string s = "3 + 5 * 2";

    cout << infixToPostfix(s) << endl;
}
