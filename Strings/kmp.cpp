/* USED FOR STRING MATCHING
The KMP matching algorithm uses degenerating property (pattern having the same sub-patterns appearing more than once in the pattern) 
of the pattern 
worst-case complexity O(n+m).  */

#include <bits/stdc++.h>
using namespace std;

class kmp{
        void compute(vector<int> &lps, string &s, int n){
        lps[0]=0;
        int len=0;
        int i=1;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    vector<int> search(string& pat, string& txt) {
        // code here
        int n=txt.length();
        int m=pat.length();
        
        vector<int> lps(m, 0);
        vector<int> ans;
        compute(lps, pat, m);
        
        int i=0, j=0;
        while(i<n){
            if(txt[i]==pat[j]){
                i++; j++;
            }
            if(j==m){
                ans.push_back(i-m);
                j=lps[j-1];
            }
            else if(i<n && j<m &&txt[i]!=pat[j]){
                if(j!=0){
                    j=lps[j-1];
                }else i++;
            }
        }
        return ans;
        
    }
};