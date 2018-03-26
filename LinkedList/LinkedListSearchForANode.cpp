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
    
    //Insert at the beginning
    void insertAtBeginning();
    
    //Insert at the end
    void insertAtEnd();
    
    //Insert at a given position
    void insertAtPosition();
    
    //Delete a Node at a given position
    void deleteAtPosition();

    //Search a Node within the list
    void searchInList();
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

void LinkedList :: insertAtBeginning()
{
    int value;
    cout << "Enter the value to be inserted:  ";
    cin >> value;
    
    struct Node* temp;
    temp = createNode(value);
    
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    
    cout << "\n Element is inserted at the beginning." << endl;
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

void LinkedList :: insertAtPosition()
{
    int value, pos, counter = 0;
    cout << "Enter the value to be inserted : " << endl;
    cin >> value;
    
    struct Node *temp, *begin, *prev;
    temp = createNode(value);
    
    cout << "Enter the position you want to add the node" << endl;
    cin >> pos;
    
    begin = head;
    while(begin != NULL)
    {
        counter += 1;
        begin = begin->next;
    }
    
    if (pos == 1)
    {
        if (head == NULL)
        {
            head = temp;
            return;
        }
        else
        {
            temp->next = head;
            head = temp;
            return;
        }
    }
    else if (pos > 1 && pos <= counter)
    {
        begin = head;
        for (int i = 1; i < pos; i++)
        {
            prev = begin;
            begin = begin->next;
        }
        prev->next = temp;
        temp->next = begin;
        return;
    }
    else
    {
        cout << "Position out of range" << endl;
    }
}

void LinkedList :: deleteAtPosition()
{
    int pos, counter;
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }
    
    cout << "Enter the position of the value to be deleted" << endl;
    cin >> pos;
    
    struct Node *current, *prev;
    current = head;
    
    if (pos == 1)
    {
        head = current->next;
        free(current);
        return;
    }
    else
    {
        while (current != NULL)
        {
            current = current->next;
            counter++;
        }
        
        if (pos > 0 && pos <= counter)
        {
            current = head;
            for(int i=1; i < pos; i++)
            {
                prev = current;
                current =current->next;
            }
            
            prev->next = current->next;
            free(current);
            return;
        }
        else
        {
            cout << "Position out of range" << endl;
        }
        
    }
}

void LinkedList :: searchInList()
{
    int value, pos = 0;
    bool flag = false;
    struct Node* current;

    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    cout << "Enter the element to be searched : ";
    cin >> value;

    current = head;
    while (current != NULL)
    {
        pos++;
        if (current->data == value)
        {
            flag = true;
            cout << "Element " << value << " found at position " << pos << endl;
            return;
        }
        current = current->next;
    }

    if (flag == false)
        cout << "Element not found" << endl;
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
    
    l1.insertAtBeginning();
    l1.insertAtBeginning();
    l1.insertAtBeginning();
    l1.insertAtEnd();
    l1.insertAtPosition();
    l1.display();
    
    l1.searchInList();
    
    return 0;
}