#include <bits/stdc++.h>
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

bool isEmpty()
{
    return top == -1;
}

// Find middle (mode = 1 → second middle, mode = 2 → first middle)
int findMiddle(int mode)
{
    int size = top + 1;

    int mid;
    if (mode == 1)
        mid = size / 2;           // second middle
    else
        mid = (size - 1) / 2;     // first middle

    int temp[n], t = -1;

    // pop until reaching middle
    for (int i = 0; i < mid; i++)
    {
        temp[++t] = pop();
    }

    int middle = stk[top]; // current top is middle

    // restore stack
    while (t != -1)
    {
        push(temp[t--]);
    }

    return middle;
}

void display()
{
    for (int i = top; i >= 0; i--)
        cout << stk[i] << " ";
    cout << endl;
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);

    cout << "Stack: ";
    display();

    cout << "Second Middle: " << findMiddle(1) << endl; // 3
    cout << "First Middle: " << findMiddle(2) << endl;  // 2
}
