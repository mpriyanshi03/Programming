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
/*void print(Node* head)
    {
        Node*temp= head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    while(head!=NULL)
        {
            cout<<head->data<<" ";
            head=head->next;
        }
    }
    */
   /* Node *takeinput()
{
    int data;
    cin>>data;
    Node * head=NULL;
    while(data!=-1)
    {
        Node *newnode=new Node(data);
        if(head==NULL)
        {
            head=newnode;
        }
        else{
            Node* temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;

            }
            temp->next=newnode;
        }
        cin>>data;

    }
    return head;
}
*/

//ALTERNATE METHOD WITH OPTIMUM TIME COMPLEXITY
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
    //statically
    /*Node n1(10);
    
    Node n2(20);
    
    Node n3(30);
    Node* head=&n2;
    n1.next=&n2;
    n2.next=&n3;
    
    print(n1.next);
    //cout<<n2.data<<" "<<n3.data<<" "<<n2.next<<" "<<&n3<<" "<<n3.next;
    */
   //DYNAMICALLY
   /*Node * n1=new Node(10);
   Node * n2=new Node(12);
   Node * n3=new Node(12);
   Node *head=n1;
   n1->next=n2;
   n2->next=n3;
   print(head);
   cout<<endl;
   print(head);
   */

}
