#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

// Rotate left by k
node* rotateLeft(node* head, int k) {
    if(!head || k == 0) return head;

    node* curr = head;
    int len = 1;

    // Find length
    while(curr->next) {
        curr = curr->next;
        len++;
    }

    // Connect last to head (circular)
    curr->next = head;

    k = k % len;

    // Move to new tail
    curr = head;
    for(int i = 1; i < k; i++) {
        curr = curr->next;
    }

    node* newHead = curr->next;
    curr->next = NULL;

    return newHead;
}

void display(node* head) {
    while(head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    node* head = new node{10, new node{20, new node{30, new node{40, new node{50, NULL}}}}};

    cout << "Before: ";
    display(head);

    head = rotateLeft(head, 4);

    cout << "After rotating by 4: ";
    display(head);
}
