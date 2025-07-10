#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;


BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
//ELEMENTS IN RANGE K1 AND K2
void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2)
{
    
}


//SEARCH IN BST
bool searchInBST(BinaryTreeNode<int>* root, int k)
{
    BinaryTreeNode<int>* temp=root;
    while(temp!=NULL)
    {
        if(temp->data==k){
            return true;
        }
        else if(temp->data>k)
        {
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
        return false;
    }
    /*if(root==NULL)
    {
        return false;
    }
    if(root->data==k)
    {
        return true;
    }
    else if(root->data<k)
    {
        return searchInBST(root->right,k);
    }
    else{
        return searchInBST(root->left,k);
    }*/

}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    cout << ((searchInBST(root, k)) ? "true" : "false");
    cout<<endl;
    int k1, k2;
    cin >> k1 >> k2;
    elementsInRangeK1K2(root, k1, k2);
    
}