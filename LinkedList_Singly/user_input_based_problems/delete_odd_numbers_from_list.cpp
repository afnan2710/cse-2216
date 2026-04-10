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

// Delete all odd numbers
node* deleteOdd(node* head) {
    // Remove odd nodes from beginning
    while(head && head->data % 2 != 0) {
        node* temp = head;
        head = head->next;
        delete temp;
    }

    node* curr = head;

    while(curr && curr->next) {
        if(curr->next->data % 2 != 0) {
            node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }

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
    node* head = NULL;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> x;
        head = insert(head, x);
    }

    cout << "Original List: ";
    display(head);

    head = deleteOdd(head);

    cout << "After deleting odd numbers: ";
    display(head);

    return 0;
}
