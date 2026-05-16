#include<bits/stdc++.h>
using namespace std;

#define maxx 5

int q[maxx];
int frontt = -1, rear = -1;

void enqueue(int x)
{
    if ((rear + 1) % maxx == frontt)
    {
        cout << "OVERFLOW\n";
        return;
    }

    if (frontt == -1)
        frontt = rear = 0;
    else
        rear = (rear + 1) % maxx;

    q[rear] = x;
}

void dequeue()
{
    if (frontt == -1)
    {
        cout << "UNDERFLOW\n";
        return;
    }

    cout << q[frontt] << endl;

    if (frontt == rear)
        frontt = rear = -1;
    else
        frontt = (frontt + 1) % maxx;
}

void show()
{
    if (frontt == -1)
    {
        cout << "Empty\n";
        return;
    }

    int i = frontt;
    while (true)
    {
        cout << q[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % maxx;
    }
    cout << endl;
}

int main()
{
    enqueue(1);
    enqueue(2);
    dequeue();   // removes 1
    enqueue(3);

    show(); // 2 3
}
