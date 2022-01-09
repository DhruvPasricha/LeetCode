// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int t[201][201][2];
    
    int solve(string &s, int i, int j, bool isTrue){
        if(i>j) return 0;
        if(i==j){
            if(isTrue) return s[i] == 'T';
            return s[i] == 'F';
        }
        if(t[i][j][isTrue]!=-1) return t[i][j][isTrue];
        int ans=0;
        for(int k=i+1; k<=j; k+=2){
            int lt = solve(s,i,k-1,true);
            int lf = solve(s,i,k-1,false);
            int rt = solve(s,k+1,j,true);
            int rf = solve(s,k+1,j,false);
            
            if(s[k]=='&'){
                if(isTrue) ans += (lt*rt);
                else ans += (lt*rf + lf*rt + lf*rf);
            }
            else if(s[k]=='|'){
                if(isTrue) ans += (lt*rt + lt*rf + lf*rt);
                else ans += (lf*rf);
            }
            else if(s[k]=='^'){
                if(isTrue) ans += (lt*rf + lf*rt);
                else ans += (lf*rf +lt*rt) ;
            }
        }
        return t[i][j][isTrue] = ans % 1003;
    }
    
    int countWays(int n, string s){
        memset(t,-1,sizeof(t));
        return solve(s,0,n-1,true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends