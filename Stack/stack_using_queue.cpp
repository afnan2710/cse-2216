#include<bits/stdc++.h>
using namespace std;

#define maxx 100

// Queue 1
int q1[maxx], f1 = -1, r1 = -1;

// Queue 2
int q2[maxx], f2 = -1, r2 = -1;

void enqueue1(int x)
{
    if (r1 == maxx - 1) return;
    if (f1 == -1) f1 = 0;
    q1[++r1] = x;
}

int dequeue1()
{
    return q1[f1++];
}

bool isEmpty1()
{
    return (f1 == -1 || f1 > r1);
}

void enqueue2(int x)
{
    if (r2 == maxx - 1) return;
    if (f2 == -1) f2 = 0;
    q2[++r2] = x;
}

int dequeue2()
{
    return q2[f2++];
}

bool isEmpty2()
{
    return (f2 == -1 || f2 > r2);
}


// push (costly)
void push(int x)
{
    // Step 1: push to q2
    enqueue2(x);

    // Step 2: move all q1 → q2
    while (!isEmpty1())
    {
        enqueue2(dequeue1());
    }

    // Step 3: swap q1 and q2
    swap(q1, q2);
    swap(f1, f2);
    swap(r1, r2);
}

// pop
void pop()
{
    if (isEmpty1())
    {
        cout << "UNDERFLOW\n";
        return;
    }
    dequeue1();
}

// peek
int peek()
{
    return q1[f1];
}

// isEmpty
bool isEmpty()
{
    return isEmpty1();
}

// display
void display()
{
    for (int i = f1; i <= r1; i++)
        cout << q1[i] << " ";
    cout << endl;
}

int main()
{
    push(1);
    push(2);

    pop();
    display();  // should show 1

    cout << (isEmpty() ? "True" : "False") << endl;
}
