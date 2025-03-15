#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> pq;

    pq.push(10);
    pq.push(100);
    pq.push(4);
    pq.push(110);

    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
}