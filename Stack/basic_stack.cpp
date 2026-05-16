#include <bits/stdc++.h>
using namespace std;

#define n 5
int stk[n];
int top = -1;

void push (int x)
{
    if (top == n-1)
    {
        cout<<"overflow"<<endl;
    }
    else
    {
        stk[++top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        cout<<"underflow"<<endl;
    }
    else
    {
        top--;
    }
}

bool isEmpty()
{
    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void show()
{
    while(!isEmpty())
    {
        cout<<stk[top]<<endl;
        pop();
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    pop();
    pop();
    push(70);
    cout<<"Size of stack is: "<<(top + 1)<<endl;
    show();
}
