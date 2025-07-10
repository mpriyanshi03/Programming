/* 
Heapify: It is the process to rearrange the elements to maintain the property of heap data structure. 
It is done when root is removed (we replace root with the last node and then call heapify to ensure that heap property is maintained)
or heap is built (we call heapify from the last internal node to root) to make sure that the heap property is maintained. 
This operation also takes O(log n) time. 
*/

#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int data)
    {
        size = size + 1;
        int index = size;
        arr[index] = data;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }

            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void del()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int left_child = 2 * i;
            int right_child = 2 * i + 1;

            if (left_child < size && arr[i] < arr[left_child])
            {
                swap(arr[i], arr[left_child]);
                i = left_child;
            }
            else if (right_child < size && arr[i] < arr[right_child])
            {
                swap(arr[i], arr[right_child]);
                i = right_child;
            }
            else
            {
                return;
            }
        }
    }
    void heapify(vector<int> &arr, int n, int i)
    {

        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[left] < arr[smallest]){
            smallest = left;
        }
        if (right < n && arr[right] < arr[smallest]){
            smallest = right;
        }

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(arr, n, smallest);
        }
    }
    void heapifymax(vector<int> &arr, int n, int i)
    {

        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
    vector<int> buildMinHeap(vector<int> &arr)
    {
        // Write your code here
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
        return arr;
    }

    void heapsort(vector<int> &arr,int n){
        int t=n;
        while(t>=1){
            swap(arr[t],arr[0]);
            t--;
            heapifymax(arr,n,0);
            }

        }


        
};

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(70);
    h.insert(54);
    h.insert(79);
    h.insert(35);
    h.insert(58);
    h.insert(90);
    h.insert(96);

    h.print();

    h.del();
    h.print();
    int arr[5]={9,3,2,6,7};
    
    vector<int> vec(arr,arr+5);
    h.heapsort(vec,5);
    
    vector<int> vec1(arr,arr+5);
    cout<<"Print the arr now"<<endl;
    for(int i=0;i<vec1.size();i++)
    {
        cout<<vec1[i]<<" ";
    }
    cout<<endl;
    cout<<"Print min heap"<<endl;
    vector<int> ans= h.buildMinHeap(vec);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
     cout<<endl;
    cout<<"Print min heap"<<endl;

    cout<<endl;




}