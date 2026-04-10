#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

// Delete all even numbers
node* deleteEven(node* head) {
    // Remove from beginning
    while(head && head->data % 2 == 0) {
        node* temp = head;
        head = head->next;
        delete temp;
    }

    node* curr = head;

    while(curr && curr->next) {
        if(curr->next->data % 2 == 0) {
            node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }

    return head;
}

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

    head = deleteEven(head);

    cout << "After deleting even numbers: ";
    display(head);
}
