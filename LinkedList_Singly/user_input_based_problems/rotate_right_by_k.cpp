#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

// Insert at end
node* insert(node* head, int val) {
    node* newNode = new node{val, NULL};

    if(head == NULL) return newNode;

    node* temp = head;
    while(temp->next) temp = temp->next;

    temp->next = newNode;
    return head;
}

// Rotate right by k
node* rotateRight(node* head, int k) {
    if(!head || !head->next || k == 0) return head;

    node* curr = head;
    int len = 1;

    // Find length
    while(curr->next) {
        curr = curr->next;
        len++;
    }

    // Make circular
    curr->next = head;

    k = k % len;
    int steps = len - k;

    curr = head;
    for(int i = 1; i < steps; i++) {
        curr = curr->next;
    }

    node* newHead = curr->next;
    curr->next = NULL;

    return newHead;
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
    node* head = NULL;
    int n, x, k;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> x;
        head = insert(head, x);
    }

    cout << "Original List: ";
    display(head);

    cout << "Enter k (rotate right): ";
    cin >> k;

    head = rotateRight(head, k);

    cout << "After rotation: ";
    display(head);

    return 0;
}
