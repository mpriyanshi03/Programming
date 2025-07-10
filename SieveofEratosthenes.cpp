#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> seiveoferatosthenes(int n)
{
    vector<bool> isPrime(n + 1, true);
    // true-> prime hai;
    // false-> prime nhi hai;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = 2; i * j <= n; j++)
            {
                isPrime[i * j] = false;
            }
        }
    }
    vector<int> result;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i] == true)
            result.push_back(i);
    }
    return result;
}

int main()
{
    cout << "Enter the limit" << endl;
    int n;
    cin >> n;
    vector<int> isPrime=seiveoferatosthenes(n);
   for(auto& it: isPrime){
    cout<<it<<" ";
   }
    cout << endl;
}