#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        next=NULL;

    }
    
};
Node *takeinput()
{
    int data;
    cin>>data;
    Node * head=NULL;
    Node* tail =NULL;
    while(data!=-1)
    {
        Node *newnode=new Node(data);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;;
        }
        else{
            tail->next=newnode;
            tail=tail->next;

            
        }
        cin>>data;

    }
    return head;
}

Node *insertNode(Node*head,int i, int data)
{
    int count=0;
    Node *temp=head;
    Node * newnode=new Node(data);
    if(i==0)
    {
        newnode->next=head;
        head=newnode;
        return head;
    }
    while(temp!=NULL && count<i-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp!=NULL)
    {
        Node * a=temp->next;
        temp->next=newnode;
        newnode->next=a;
    }
    return head;

    
}
void print(Node*head)
{ 
    
    while(head!=NULL)
        {
            cout<<head->data<<" ";
            head=head->next;
        }
}
int main()
{
    Node* head=takeinput();
    print(head);
    int i,data;
    cin>>i>>data;
    head=insertNode(head,i,data);
    print(head);


}
