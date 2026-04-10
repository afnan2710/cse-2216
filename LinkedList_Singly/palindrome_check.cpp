#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

// Check palindrome
bool isPalindrome(node* head) {
    vector<int> v;

    while(head) {
        v.push_back(head->data);
        head = head->next;
    }

    int i = 0, j = v.size() - 1;

    while(i < j) {
        if(v[i] != v[j]) return false;
        i++; j--;
    }

    return true;
}

void display(node* head) {
    while(head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    node* head = new node{1, new node{2, new node{2, new node{1, NULL}}}};

    display(head);

    if(isPalindrome(head))
        cout << "YES\n";
    else
        cout << "NO\n";
}
