// WAP to delete node in linked list.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node *head = nullptr;

void insert(int data)
{
    Node *newNode = new Node(data);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deletenode()
{
    if (!head)
    {
        cout << "The list is empty." << endl;
        return;
    }

    int value;
    cout << "Enter an element to delete from the linked list: ";
    cin >> value;

    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Node with value " << value << " deleted." << endl;
        return;
    }

    Node *current = head;
    Node *previous = nullptr;

    while (current && current->data != value)
    {
        previous = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Node with value " << value << " not found." << endl;
        return;
    }

    previous->next = current->next;
    delete current;
    cout << "Node with value " << value << " deleted." << endl;
}

void printList()
{
    Node *temp = head;
    if (!temp)
    {
        cout << "The list is empty." << endl;
        return;
    }
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    cout << "Initial Linked List: ";
    printList();

    deletenode(); 
    cout << "Linked List after deletion: ";
    printList();

    return 0;
}
