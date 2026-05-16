#include <bits/stdc++.h>
using namespace std;

#define n 100

int stk[n], top = -1;
int temp[n], top2 = -1;

// original stack
void push(int x)
{
    stk[++top] = x;
}

int pop()
{
    return stk[top--];
}

int peek()
{
    return stk[top];
}

bool isEmpty()
{
    return (top == -1);
}

// temp stack
void push2(int x)
{
    temp[++top2] = x;
}

int pop2()
{
    return temp[top2--];
}

int peek2()
{
    return temp[top2];
}

bool isEmpty2()
{
    return (top2 == -1);
}

// sort stack
void sortStack()
{
    while (!isEmpty())
    {
        int curr = pop();

        while (!isEmpty2() && peek2() > curr)
        {
            push(pop2());
        }

        push2(curr);
    }

    // copy back
    while (!isEmpty2())
    {
        push(pop2());
    }
}

void display()
{
    for (int i = top; i >= 0; i--)
        cout << stk[i] << " ";
    cout << endl;
}

int main()
{
    push(3);
    push(1);
    push(2);

    cout << "Original: ";
    display();

    sortStack();

    cout << "Sorted: ";
    display();
}


/*
#include <bits/stdc++.h>
using namespace std;

void sortStack(stack<int> &s)
{
    stack<int> temp;

    while (!s.empty())
    {
        int curr = s.top();
        s.pop();

        // move elements back to original stack
        while (!temp.empty() && temp.top() > curr)
        {
            s.push(temp.top());
            temp.pop();
        }

        temp.push(curr);
    }

    // copy back to original stack
    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}

void display(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;

    s.push(3);
    s.push(1);
    s.push(2);

    cout << "Original: ";
    display(s);

    sortStack(s);

    cout << "Sorted: ";
    display(s);
}
*/
