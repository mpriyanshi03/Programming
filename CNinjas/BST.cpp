#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

 Node(int data)
{
    this->data=data;
    this->left=NULL;
    this->right=NULL;
}
};

// ELEMENTS IN RANGE
void elementsInRangeK1K2(Node* root, int k1, int k2)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data>k1)
    {
        elementsInRangeK1K2(root->left,k1,k2);

    }
    if(root->data>=k1 && root->data<=k2)
    {
        cout<<root->data<<" ";
    }
    if(root->data<k2)
    {
        elementsInRangeK1K2(root->right,k1,k2);
    }


}

//CHECK BST
bool isBSTHelper(Node *root,int min,int max)
{ 
    if(root==NULL)
    {
        return true;
    }
    if(root->data>=min && root->data<=max)
    {
        bool left=isBSTHelper(root->left,min,root->data);
        bool right=isBSTHelper(root->right,root->data,max);
        return left && right;
    }
    else{
        return false;
    }

}

bool isBST(Node *root)
{
    return isBSTHelper(root, INT_MIN,INT_MAX);
}

//LEVEL ORDER
void levelordertraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}


//LEVEL ORDER TRAVERSAL 
void levelordertraversalenter(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}


//TAKE INPUT
Node* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    Node *root = new Node(rootData);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
       Node *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            Node* leftNode = new Node(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            Node* rightNode = new Node(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

Node* InsertIntoBST(Node* root, int data)
{
    if(root==NULL)
    {
        root=new Node(data);
        return root;
    }
    if(data<root->data)
    {
        root->left=InsertIntoBST(root->left,data);

    }
    else{
        root->right=InsertIntoBST(root->right,data);
    }
    return root;
}
void createinput(Node* &root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        root=InsertIntoBST(root,data);
        cin>>data;
    }
}

void postorder(Node* root){
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}


int main()
{
    Node  *root= NULL;
    //takeInput();
    
    createinput(root);
    

    postorder(root);
    cout<<endl;
    levelordertraversal(root);
    cout<<endl;
    levelordertraversalenter(root);
    //int k1, k2;
    //cin >> k1 >> k2;
    //elementsInRangeK1K2(root, k1, k2);
    cout<<endl;
    cout << (isBST(root) ? "true" : "false");



}

