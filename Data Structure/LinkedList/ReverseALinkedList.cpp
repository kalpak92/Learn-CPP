#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList
{
    Node *head;
public:
    LinkedList() : head(NULL)
    {}
    
    //getter for head
    Node* getHead();
    
    //create a node
    Node* createNode(int x);
    
    //Print the LinkedList
    void display();
    
    //Insert at the end
    void insertAtEnd();

    //Reverse a Linked List
    void reverseLinkedList();
    
};

Node* LinkedList :: getHead()
{
    return head;
}

Node* LinkedList :: createNode(int x)
{
    struct Node* temp;
    temp = new(struct Node);
    
    if (temp == NULL)
    {
        cout << "Memory unavailable " << endl;
        return NULL;
    }
    else
    {
        temp->data = x;
        temp->next = NULL;
        return temp;
    }
}

void LinkedList :: insertAtEnd()
{
    int value;
    cout << "Enter the value to be inserted: ";
    cin >> value ;
    struct Node *temp, *begin;
    //struct Node* begin;
    temp = createNode(value);
    
    if (head == NULL)
    {
        head = temp;
        return;
    }
    
    begin = head;
    while (begin->next != NULL)
    {
        begin = begin->next;
    }
    
    begin->next = temp;
    return;
}

void LinkedList :: reverseLinkedList()
{
    Node *prev = NULL;
    Node *current = head;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

void LinkedList :: display()
{
    Node* temp = new Node;
    temp = head;
    cout << "Displaying the linked list : " << ' ';
    
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    LinkedList l1;
    
    l1.insertAtEnd();
    l1.insertAtEnd();
    l1.insertAtEnd();
    l1.insertAtEnd();
    l1.insertAtEnd();
    l1.display();
    
    l1.reverseLinkedList();
    cout << "The reversed Linked List is : ";
    l1.display();
    
    return 0;
}