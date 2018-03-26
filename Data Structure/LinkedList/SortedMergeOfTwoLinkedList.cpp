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

Node* SortedMerge(Node *head1, Node *head2)
{
    Node *temp = NULL;
    if (head1 == NULL)
        return head2;
    else if(head2 == NULL)
        return head1;

    if (head1->data <= head2->data)
    {
        temp = head1;
        temp->next = SortedMerge(head1->next, head2);
    }
    else
    {
        temp = head2;
        temp->next = SortedMerge(head1, head2->next);
    }

    return temp;
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

    LinkedList l2;
    
    l2.insertAtEnd();
    l2.insertAtEnd();
    l2.insertAtEnd();
    l2.insertAtEnd();
    l2.insertAtEnd();
    l2.display();
    
    Node *result = SortedMerge(l1.getHead(), l2.getHead());

    cout << "The Sorted Megred Linked List is :" << endl;

    while (result != NULL)
    {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}