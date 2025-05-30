/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            int n = intervals.size();
            
            vector<vector<int>> ans;
            sort(intervals.begin(), intervals.end());
            ans.push_back(intervals[0]);
    
            for (int i = 1; i < n; i++) {
                int start = intervals[i][0];
                int end = intervals[i][1];
    
                if(start<=ans.back()[1]){
                    ans.back()[1] = max(ans.back()[1], end);
                }
                else{
                    ans.push_back(intervals[i]);
                }
            }
    
            return ans;
        }
    };
