#include <bits/stdc++.h>
using namespace std;

struct tNode
{
    int data;
    struct tNode *left;
    struct tNode *right;
};

struct tNode *newtNode(int data)
{
    struct tNode *node = new tNode;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

void inorder(tNode* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}



//FLATTEN TREE
void flatten(tNode *root)
{
    tNode *current=root;
    tNode* prev;
    if(root==NULL)
    {
        return ;
    }
    while(current!=NULL)
    {
        if(current->left!=NULL)
        {
            prev=current->left;
            while(prev->right!=NULL)
            {
                prev=prev->right;
            }
            prev->right=current->right;
            current->right=current->left;
            current->left=NULL;
        }
        current=current->right;
        
            
        }
        cout<<endl;
        inorder(root);
}



//MORRIS TRAVERSAL
void MorrisTraversal(tNode *root)
{
    tNode *current, *pred;

    current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            pred = current->left;
            while (pred->right != NULL && pred->right != current)
            {
                pred = pred->right;
            }
            if (pred->right == NULL)
            {
                pred->right = current;
                current = current->left;
            }
            else
            {
                pred->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

int main()
{

    /* Constructed binary tree is
            1
          /   \
         2     3
       /   \
      4     5
  */
    struct tNode *root = newtNode(1);
    root->left = newtNode(2);
    root->right = newtNode(3);
    root->left->left = newtNode(4);
    root->left->right = newtNode(5);

    MorrisTraversal(root);
    flatten(root);
    

    return 0;
}
