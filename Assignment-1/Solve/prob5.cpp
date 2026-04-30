#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

node* insert(node* head, int val) {
    node* newNode = new node{val, NULL, NULL};
    if (!head)
        return newNode;

    node* temp = head;

    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

node* deleteAll(node* head, int num) {
    node* curr = head;

    while (curr) {
        if (curr->data == num) {
            node* temp = curr;

            if (curr->prev)
                curr->prev->next = curr->next;
            else
                head = curr->next;

            if (curr->next)
                curr->next->prev = curr->prev;

            curr = curr->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

void display(node* head) {
    while (head) {
        cout<<head->data;
        if (head->next)
            cout<<" <-> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node* head = NULL;

    int a[] = {7,12,8,12,10,12};
    for (int i=0; i<6; i++)
        head = insert(head, a[i]);

    head = deleteAll(head, 12);
    display(head);

    head = NULL;

    int b[] = {5,5,5,5};
    for (int i=0; i<4; i++)
        head = insert(head, b[i]);

    head = deleteAll(head, 5);
    display(head);
}

/*
step 1: traverse list
step 2: if node value == num then delete it
step 3: update both prev and next links
step 4: handle head separately
*/
