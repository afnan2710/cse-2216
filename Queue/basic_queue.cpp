#include<bits/stdc++.h>
using namespace std;

#define maxx 100

int q[maxx];
int frontt = -1, rear = -1;

void enqueue(int x)
{
    if(rear == maxx - 1)
        cout << "OVERFLOW" << endl;
    else
    {
        if(frontt == -1)
            frontt = 0;

        rear++;
        q[rear] = x;
    }
}

bool isempty()
{
    if(frontt == -1 || frontt > rear)
        return true;
    else
        return false;
}

void dequeue()
{
    if(isempty())
        cout << "UNDERFLOW" << endl;
    else
        frontt++;
}

int size()
{
    if(isempty())
        return 0;

    return rear - frontt + 1;
}

int frontelement()
{
    return q[frontt];
}

void show()
{
    if(isempty())
    {
        cout << "Queue is Empty" << endl;
        return;
    }

    for(int i = frontt; i <= rear; i++)
    {
        cout << q[i] << " ";
    }
    cout << endl;
}

int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(24);

    cout << "The front element in queue is " << frontelement() << endl;

    cout << "Size of queue " << size() << endl;

    show();
    return 0;
}
