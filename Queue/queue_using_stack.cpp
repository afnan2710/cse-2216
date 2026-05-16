#include<bits/stdc++.h>
using namespace std;

#define n 100

// Stack 1
int s1[n], top1 = -1;

// Stack 2
int s2[n], top2 = -1;

// stack operations
void push1(int x) { s1[++top1] = x; }
int pop1() { return s1[top1--]; }
bool isEmpty1() { return top1 == -1; }

void push2(int x) { s2[++top2] = x; }
int pop2() { return s2[top2--]; }
bool isEmpty2() { return top2 == -1; }

// enqueue
void enqueue(int x)
{
    push1(x);
}

// dequeue
void dequeue()
{
    if (isEmpty1() && isEmpty2())
    {
        cout << "UNDERFLOW\n";
        return;
    }

    if (isEmpty2())
    {
        while (!isEmpty1())
        {
            push2(pop1());
        }
    }

    pop2();
}

// display
void display()
{
    // print s2 (front part)
    for (int i = top2; i >= 0; i--)
        cout << s2[i] << " ";

    // print s1 (rear part)
    for (int i = 0; i <= top1; i++)
        cout << s1[i] << " ";

    cout << endl;
}

bool isEmpty()
{
    return isEmpty1() && isEmpty2();
}

int main()
{
    enqueue(1);
    enqueue(2);

    dequeue(); // 1

    display(); // 2

    cout << (isEmpty() ? "True" : "False") << endl;
}
