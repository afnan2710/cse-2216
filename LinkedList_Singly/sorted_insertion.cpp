#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

// Insert in sorted order
node* sortedInsert(node* head, int val) {
    node* newNode = new node{val, NULL};

    // Insert at beginning
    if(head == NULL || val < head->data) {
        newNode->next = head;
        return newNode;
    }

    node* curr = head;

    // Find correct position
    while(curr->next != NULL && curr->next->data < val) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

// Display list
void display(node* head) {
    while(head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    node* head = new node{1, new node{4, new node{6, new node{7, new node{9, new node{11, NULL}}}}}};

    cout << "Before: ";
    display(head);

    head = sortedInsert(head, 3);

    cout << "After inserting 3: ";
    display(head);
}
