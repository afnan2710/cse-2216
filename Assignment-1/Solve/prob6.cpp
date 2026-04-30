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

void findPairs(node* head, int target) {
    if (!head)
        return;

    node* left = head;
    node* right = head;

    while (right->next)
        right = right->next;

    bool found = false;

    while (left!=right && right->next!=left) {
        int sum = left->data+right->data;

        if (sum == target) {
            cout<<"("<<left->data<<","<<right->data<<") ";
            found = true;
            left = left->next;
            right = right->prev;
        }
        else if (sum < target) {
            left = left->next;
        }
        else {
            right = right->prev;
        }
    }

    if (!found)
        cout<<"No pairs found";

    cout<<endl;
}

int main()
{
    node* head = NULL;

    int a[] = {1,2,3,4,5,6};
    for (int i=0; i<6; i++)
        head = insert(head, a[i]);

    findPairs(head, 7);

    int b[] = {2,4,6,8,10};
    for (int i=0; i<5; i++)
        head = insert(head, b[i]);

    findPairs(head, 12);

}

/*
step 1: use two pointers (start and end)
step 2: if sum == target -> print pair
step 3: if sum < target -> move left forward
step 4: if sum > target -> move right backward
step 5: continue until pointers meet
*/
