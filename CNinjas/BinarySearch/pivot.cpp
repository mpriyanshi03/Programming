// TO FIND THE PIVOT THAT IS IF IN A ROTATED ARRAY YOUHAVE TO FINDTHE PIVOT FROM WHERE IT IS STARTING
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &nums, int n)
{
    int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[r])
        {
            l = mid + 1;
        }
        else
            r = mid;
    }
    return r;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int n = arr.size();
    int idx = find(arr, n);
    cout << idx << endl;
}