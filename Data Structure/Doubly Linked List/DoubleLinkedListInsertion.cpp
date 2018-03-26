#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoubleLinkedList
{
    Node *head;
public:
    DoubleLinkedList() : head(NULL)
    {}
    
    //getter for head
    Node* getHead();
    
    //create a node
    Node* createNode(int x);

    //insert at beginning
    void insertAtBeginning();

    //insert at the end
    void insertAtEnd();
    
    //insert after a given node
    void insertAfterAGivenNode(Node *n);

    //Print the LinkedList
    void display();
};

Node* DoubleLinkedList :: getHead()
{
	return head;
}

Node* DoubleLinkedList :: createNode(int x)
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
        temp->prev = NULL;
        temp->next = NULL;
        return temp;
    }
}

void DoubleLinkedList :: insertAtBeginning()
{
    int value;
    cout << "Enter the value to be inserted: ";
    cin >> value ;

    Node *temp;
    temp = createNode(value);

    temp->next = head;

    if (head != NULL)
    {
        head->prev = temp;
    }
    head = temp;
}

void DoubleLinkedList :: insertAtEnd()
{
	int value;
    cout << "Enter the value to be inserted: ";
    cin >> value ;
    struct Node *temp, *begin;

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
    temp->prev = begin;
    return;
}

void DoubleLinkedList :: insertAfterAGivenNode(Node *prev)
{
    int value;
    cout << "Enter the value to be inserted: ";
    cin >> value ;

    Node *temp;
    temp = createNode(value);

    temp->next = prev->next;
    prev->next = temp;

    if (temp->next != NULL)
        temp->next->prev = temp;
}

void DoubleLinkedList :: display()
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
    DoubleLinkedList l1;
    
    l1.insertAtEnd();
    l1.insertAtEnd();
    l1.insertAtEnd();
    l1.insertAtBeginning();

    Node *head = l1.getHead();
    l1.insertAfterAGivenNode(head->next->next);
    
    l1.display();
    
    return 0;
}