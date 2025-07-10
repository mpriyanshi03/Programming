#include <bits/stdc++.h>
using namespace std;

class maxheap{
    public:
    int arr[1000];
    int size;

    maxheap()
    {
        size = 0;
    }

    void insert(int data){
        int index=size;
        arr[index]=data;
        size++;

        while(index>0){
            int parent=(index-1)/2;

            if(arr[parent]<arr[index]){
                swap(arr[parent], arr[index]);
                index=parent;
            }
            else break;

        }

    }

    void deletenode(){
        if (size == 0) {
            cout << "Heap is empty.\n";
            return;
        }

        int i=0;
        arr[0]=arr[size-1];
        size--;

        while(i<size){
            int leftindex=2*i+1;
            int rightindex=2*i+2;

            if(leftindex<size && arr[leftindex]>arr[i]){
                swap(arr[leftindex],arr[i]);
                i=leftindex;
            }
            else if(rightindex<size && arr[rightindex]>arr[i]){
                swap(arr[rightindex],arr[i]);
                i=rightindex;
            }
            else{
                return;
            }

        }
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    maxheap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(66);
    h.insert(34);
    h.insert(78);
    h.insert(54);
    h.insert(80);
    h.insert(80);

    h.deletenode(); 

    cout << "Max Heap (0-based): ";
    h.print();

    return 0;
}