#include <bits/stdc++.h>
using namespace std;

#define n 100
int stk[n];
int top = -1;

void push(int x)
{
    if (top == n - 1)
        cout << "overflow\n";
    else
        stk[++top] = x;
}

int pop()
{
    if (top == -1)
        return -1;
    else
        return stk[top--];
}

bool isEmpty()
{
    return (top == -1);
}

// Insert element at bottom
void insertAtBottom(int x)
{
    if (isEmpty())
    {
        push(x);
        return;
    }

    int temp = pop();
    insertAtBottom(x);
    push(temp);
}

// Reverse stack using recursion
void reverseStack()
{
    if (isEmpty())
        return;

    int temp = pop();
    reverseStack();
    insertAtBottom(temp);
}

// Display stack (without destroying original logic)
void display()
{
    for (int i = top; i >= 0; i--)
    {
        cout << stk[i] << " ";
    }
    cout << endl;
}

int main()
{
    push(3);
    push(2);
    push(1);

    cout << "Original Stack: ";
    display();

    reverseStack();

    cout << "Reversed Stack: ";
    display();
}


/*
#include <bits/stdc++.h>
using namespace std;

#define n 100

int stk[n], top = -1;
int temp1[n], top1 = -1;
int temp2[n], top2 = -1;

// original stack
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
    return (top == -1);
}

// temp1
void push1(int x) { temp1[++top1] = x; }
int pop1() { return temp1[top1--]; }

// temp2
void push2(int x) { temp2[++top2] = x; }
int pop2() { return temp2[top2--]; }

// reverse without recursion
void reverseStack()
{
    // Step 1: original → temp1
    while (!isEmpty())
    {
        push1(pop());
    }

    // Step 2: temp1 → temp2
    while (top1 != -1)
    {
        push2(pop1());
    }

    // Step 3: temp2 → original
    while (top2 != -1)
    {
        push(pop2());
    }
}

// display
void display()
{
    for (int i = top; i >= 0; i--)
        cout << stk[i] << " ";
    cout << endl;
}

int main()
{
    push(3);
    push(2);
    push(1);

    cout << "Original Stack: ";
    display();

    reverseStack();

    cout << "Reversed Stack: ";
    display();
}
*/
