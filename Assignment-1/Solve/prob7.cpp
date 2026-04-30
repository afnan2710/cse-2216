#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

node* insert(node* head, int val) {
    node* newNode = new node{val, NULL};

    if (!head)
        return newNode;

    node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

node* removeDuplicates(node* head) {
    node* curr = head;

    while (curr) {
        node* temp = curr;

        while (temp->next) {
            if (temp->next->data == curr->data) {
                node* del = temp->next;
                temp->next = del->next;
                delete del;
            } else {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

void display(node* head) {
    while (head) {
        cout<<head->data;
        if (head->next)
            cout<<" -> ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    node* head = NULL;

    int a[] = {4,2,5,4,2,3,4};
    for (int i = 0; i < 7; i++)
        head = insert(head, a[i]);

    head = removeDuplicates(head);
    display(head);

    head = NULL;

    int b[] = {1,1,1,2,3,2};
    for (int i = 0; i < 6; i++)
        head = insert(head, b[i]);

    head = removeDuplicates(head);
    display(head);
}

/*
step 1: take each node as current
step 2: check all next nodes
step 3: if duplicate found -> delete it
step 4: continue until all duplicates removed
*/
