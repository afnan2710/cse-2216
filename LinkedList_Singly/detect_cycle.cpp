#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

// Detect cycle (Floyd's algorithm)
bool hasCycle(node* head) {
    node* slow = head;
    node* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }

    return false;
}

int main() {
    // Creating nodes
    node* head = new node{3, NULL};
    node* n2 = new node{2, NULL};
    node* n3 = new node{0, NULL};
    node* n4 = new node{4, NULL};

    // Linking
    head->next = n2;
    n2->next = n3;
    n3->next = n4;

    // Creating cycle
    n4->next = n2;

    if(hasCycle(head))
        cout << "YES\n";
    else
        cout << "NO\n";
}
