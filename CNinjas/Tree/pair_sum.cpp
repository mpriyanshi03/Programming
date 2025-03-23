#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void inorder(BinaryTreeNode<int>* root, vector<int>&in)
{
  if(root==NULL)
  {
    return ;
  }
  inorder(root->left, in);
  in.push_back(root->data);
  inorder(root->right, in);
}

void pairSum(BinaryTreeNode<int> *root, int target)
{
  if(root==NULL)
  {
    return;
  }
  vector<int> InorderVal;
  inorder(root,InorderVal);

  int i=0 , j=InorderVal.size();

  while(i<j)
  {
    int sum=InorderVal[i]+InorderVal[j];
    if(sum==target)
    {
      cout<< InorderVal[j] <<" "<< InorderVal[i]<<endl;
      i++;
      j--;
    }
    else if(sum>target)
    {
      j--;
    }
    else{
      i++;
    }

  }
}


int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}