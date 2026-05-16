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

void pop()
{
    if (top == -1)
        cout << "underflow\n";
    else
        top--;
}

char peek()
{
    return stk[top];
}

bool isEmpty()
{
    return (top == -1);
}

bool isPalindrome(string str)
{
    string clean = "";

    // clean string
    for (char ch : str)
    {
        if (ch != ' ')
        {
            ch = tolower(ch);
            clean += ch;
            push(ch);
        }
    }

    // compare
    for (char ch : clean)
    {
        if (ch != peek())
            return false;
        pop();
    }

    return true;
}

int main()
{
    string s1 = "A man a plan a canal Panama";
    string s2 = "hello";

    cout << (isPalindrome(s1) ? "True" : "False") << endl;

    // reset stack
    top = -1;

    cout << (isPalindrome(s2) ? "True" : "False") << endl;
}


/*
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    stack<char> st;
    string clean = "";

    // Step 1: remove spaces + lowercase
    for (char ch : str)
    {
        if (ch != ' ')
        {
            clean += tolower(ch);
            st.push(tolower(ch));
        }
    }

    // Step 2: compare
    for (char ch : clean)
    {
        if (ch != st.top())
            return false;
        st.pop();
    }

    return true;
}

int main()
{
    string s1 = "A man a plan a canal Panama";
    string s2 = "hello";

    cout << (isPalindrome(s1) ? "True" : "False") << endl;
    cout << (isPalindrome(s2) ? "True" : "False") << endl;
}
*/
