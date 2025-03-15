#include <iostream>
#include<algorithm>
using namespace std;

int duplicate(int arr[],int n)
{
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==arr[i+1])
        {
            return arr[i];
        }
        
        
    }
}

int main()
{
    int n;
    cout<<"enter"<<endl;
    cin>>n;
    int arr[500];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int ans=duplicate(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<ans<<endl;
}
