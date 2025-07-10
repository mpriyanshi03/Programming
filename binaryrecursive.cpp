#include <iostream>
using namespace std;

int binarySearchhelper(int input[],int si,int ei,int element)
{
    int mid=(si+ei)/2;

    if(si>ei)
    {
        return -1;
    }
    if(input[mid]==element)
    {
        return mid;
    }
    if(input[mid]>element)
    {
        binarySearchhelper(input,si,mid-1,element);
    }
    else{
        binarySearchhelper(input,mid+1,ei,element);
    }
}

int binarySearch(int input[],int length,int element)
{
    int si=0;
    int ei=length-1;
    binarySearchhelper(input,si,ei,element);
}



int main() {
    int input[100000],length,element, ans;
    cout<<"enter"<<endl;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}