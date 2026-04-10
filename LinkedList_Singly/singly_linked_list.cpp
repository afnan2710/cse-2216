#include <bits/stdc++.h>
using namespace std;

// Define node structure
struct node
{
    int data;
    node *next;
};

// Insert at end
void insert(node *s, int val)
{
    while(s->next != NULL)
    {
        s = s->next;
    }

    s->next = (node*)malloc(sizeof(node));
    s->next->data = val;
    s->next->next = NULL;
}

// Delete all occurrences of a value
void deleteNode(node *s, int val)
{
    while(s->next != NULL)
    {
        if(s->next->data == val)
        {
            node* temp = s->next;
            s->next = temp->next;
            free(temp); // free memory
        }
        else
        {
            s = s->next;
        }
    }
}

// Display linked list
void display(node *s)
{
    cout << "Linked List: ";
    while(s->next != NULL)
    {
        cout << s->next->data << " -> ";
        s = s->next;
    }
    cout << "NULL" << endl;
}

// Count occurrences of a value
void search(node *s, int val)
{
    int counter = 0;

    while(s->next != NULL)
    {
        if(s->next->data == val)
        {
            counter++;
        }
        s = s->next;
    }

    cout << "Value " << val << " appears " << counter << " times." << endl;
}

// Find middle node using slow-fast pointer
void middleNode(node *s)
{
    node *slow = s->next;  // start from first actual node
    node *fast = s->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element: " << slow->data << endl;
}

// Reverse linked list
node* reverseList(node *s)
{
    node *curr = s;
    node *prev = NULL;
    node *next;

    while(curr != NULL)
    {
        next = curr->next;   // store next node
        curr->next = prev;   // reverse link
        prev = curr;         // move prev forward
        curr = next;         // move curr forward
    }

    return prev; // new head
}

// Detect cycle using Floyd’s Cycle Detection
void cycleDetect(node *head)
{
    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            cout << "Cycle Detected in the list!" << endl;
            return;
        }
    }

    cout << "No cycle found." << endl;
}

// Calculate size of list
int size(node *s)
{
    int count = 0;

    while(s->next != NULL)
    {
        count++;
        s = s->next;
    }

    return count;
}

// MAIN FUNCTION
int main()
{
    // Create dummy head node
    node *head = (node*)malloc(sizeof(node));
    head->next = NULL;

    cout << "=== Inserting Elements ===" << endl;
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    display(head);

    cout << "\n=== Deleting value 3 ===" << endl;
    deleteNode(head, 3);
    display(head);

    cout << "\n=== Inserting more elements ===" << endl;
    insert(head, 3);
    insert(head, 3);
    insert(head, 3);
    insert(head, 7);
    display(head);

    cout << "\n=== Searching occurrences of 3 ===" << endl;
    search(head, 3);

    cout << "\n=== Finding Middle Element ===" << endl;
    middleNode(head);

    cout << "\n=== Reversing the List ===" << endl;
    head->next = reverseList(head->next);
    display(head);

    cout << "\n=== Cycle Detection ===" << endl;
    cycleDetect(head->next);

    cout << "\n=== Size of Linked List ===" << endl;
    cout << "Size: " << size(head) << endl;

    return 0;
}
