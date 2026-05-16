#include<bits/stdc++.h>
using namespace std;

#define maxx 100

int q[maxx];
int frontt = -1, rear = -1;

void enqueue(int x)
{
    if (rear == maxx - 1)
        return;

    if (frontt == -1)
        frontt = 0;

    q[++rear] = x;
}

int dequeueVal()
{
    int val = q[frontt++];
    return val;
}

bool isempty()
{
    return (frontt == -1 || frontt > rear);
}

// reverse using recursion
void reverseQueue()
{
    if (isempty())
        return;

    int x = dequeueVal();
    reverseQueue();
    enqueue(x);
}

void show()
{
    for (int i = frontt; i <= rear; i++)
        cout << q[i] << " ";
    cout << endl;
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);

    reverseQueue();

    show(); // 3 2 1
}

/*
#include<bits/stdc++.h>
using namespace std;

#define maxx 100

int q[maxx];
int frontt = -1, rear = -1;

// stack for reversal
int stk[maxx];
int top = -1;

void push(int x)
{
    stk[++top] = x;
}

int pop()
{
    return stk[top--];
}

// queue functions
void enqueue(int x)
{
    if (rear == maxx - 1)
        return;

    if (frontt == -1)
        frontt = 0;

    q[++rear] = x;
}

int dequeueVal()
{
    return q[frontt++];
}

bool isempty()
{
    return (frontt == -1 || frontt > rear);
}

// reverse WITHOUT recursion
void reverseQueue()
{
    // Step 1: queue → stack
    while (!isempty())
    {
        push(dequeueVal());
    }

    // reset queue
    frontt = 0;
    rear = -1;

    // Step 2: stack → queue
    while (top != -1)
    {
        enqueue(pop());
    }
}

void show()
{
    for (int i = frontt; i <= rear; i++)
        cout << q[i] << " ";
    cout << endl;
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);

    reverseQueue();

    show(); // 3 2 1
}
*/
