#include<bits/stdc++.h>
using namespace std;



bool palindrom(string s, int i,int j){
    if(i>=j){
        return true;
    }
    
    if(s[i]!=s[j]){
        return false;
    }
    
    return palindrom(s,i+1,j-1);
}

void reverse(int a[],int n,int i,int j){
    
    if(i>=j){
        return ; 
    }
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
    
    reverse(a,n,i+1,j-1);

}
int fact(int n){
    if(n==1){
        return 1;
    }
    return n*fact(n-1);
}
int sum(int n){
    int s=0;
    if(n<1){
        return s;
    }
    s=n+sum(n-1);

}

void print(int n,int sum){
    
    if(n<1){
        cout<<sum<<endl;
        return;
    }
    sum+=n;
    print(n-1,sum);

   
}

int fibo(int n){
    if(n<=1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}

int main()
{
    int n;
    cin>>n;
    vector<int> ans(n);
    int a=1;
    int b=1;
    ans[0]=a;
    ans[1]=b;
    for(int i=2;i<n;i++){
        ans[i]=ans[i-1]+ans[i-2];

    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    cout<<fibo(n)<<" ";



    /*string s;
    cin>>s;
    int n=s.length();
    bool pal=palindrom(s,0,n-1);
    cout<<"Palindrom: "<<pal<<endl;

    int arr[5]={1,2,3,4,5};
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    

    
    reverse(arr,5,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }

    int n;
    cin>>n;
    print(n,0);
    int s=sum(n);
    cout<<s<<endl;
    int f=fact(n);
    cout<<f<<endl;*/
}