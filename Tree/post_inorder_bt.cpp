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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

BinaryTreeNode<int> * solve(int* post,int posts,int poste,int* in,int ins,int ine)
{
    if(posts>poste)
    {
        return NULL;
    }
    int rootdata=post[poste];
    BinaryTreeNode<int> * root=new BinaryTreeNode<int>(rootdata);
    int rootindex=-1;
    for(int i=ins;i<=ine;i++)
    {
        if(in[i]==rootdata)
        {
            rootindex=i;
            break;
        }

    }
    int lins=ins;
    int line=rootindex-1;
    int rins=rootindex+1;
    int rine=ine;
    int lposts=posts;
    int rposte=poste-1;
    int lposte=line-lins+lposts;
    int rposts=lposte+1;

    root->left=solve(post,lposts,lposte,in,lins,line);
    root->right=solve(post,rposts,rposte,in, rins,rine);
    return root;

}

BinaryTreeNode<int> *buildTree(int* post, int pn, int* inorder, int in)
{
    return solve(post,0, pn-1, inorder, 0, in-1);
}

int main() {
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in, size);
    printLevelATNewLine(root);
}