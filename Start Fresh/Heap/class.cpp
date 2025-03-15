#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap()
    {
        arr[0]=-1;
        size=0;
    }

    void insert(int data){
        size=size+1;
        int index=size;
        arr[index]=data;

        while(index>1)
        {
            int parent=index/2;
            if(arr[parent] < arr[index]){ 
                swap(arr[parent],arr[index]);
                index=parent;
            }

            else{
                return;
            }
        }
    }

    void print()
    {
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void del()
    {
        if(size==0)
        {
            cout<<"nothing to delete"<<endl;
            return;
        }
        arr[1]=arr[size];
        size--;

        int i=1;
        while(i<size){ 
            int left_child=2*i;
            int right_child=2*i+1;

            if(left_child<size && arr[i]<arr[left_child])
            {
                swap(arr[i], arr[left_child]);
                i=left_child;
            }
            else if(right_child<size && arr[i]<arr[right_child])
            {
                swap(arr[i], arr[right_child]);
                i=right_child;
            }
            else{
                return;
            }
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
    
}