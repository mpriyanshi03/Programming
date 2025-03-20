#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    public:
    //CONSTRUCTOR
    Node(int data)
    {
        this->data=data;
        prev=NULL;
        next=NULL;
    }

void print(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<endl;
}
};


//LENGTH
int getLength(Node* &head)
{
    int l=0;
    while(head!=NULL)
    {
        l++;
        head=head->next;
    }
    return l;
}

//INSERTATHEAD
Node* inserathead(Node* &head, int data)
{
    Node* newnode = new Node(data);
    newnode->next = head;
    if (head != nullptr) {
        head->prev = newnode;
    }
    head = newnode;
    return head;
}

/*Node* inserathead(Node* &head, int data)
{
    Node* newnode = new Node(data);
    newnode->next = head;
    if (head != nullptr) {
        head->prev = newnode;
    }
    head = newnode;
    return head;
}*/




int main()
{ 
    Node * node1=new Node(10);
    Node* head=node1;

    head->print(head);
    cout<<getLength(head)<<endl;
    inserathead(head,20);
    head->print(head);
}


