// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    
    int dp[101][101];
    
    int solve(vector<pair<int,int>> &A, int left, int right) {
        
        if(left >= right) {
            return 0;
        }
        
        int &ans = dp[left][right];
        
        if(ans != -1) 
            return ans;
        
        ans = INT_MAX;
        
        for(int k = left;k < right;k++) {
            
            int leftAns = solve(A, left, k);
            int rightAns = solve(A, k + 1, right);
            
            int cur = leftAns + rightAns + (A[left].first * A[k].second * A[right].second);
            
            ans = min(ans, cur);
            
        }
        
        
        return ans;
        
        
    }
    
    
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        
        vector<pair<int,int>> matrices(N - 1);
        
        for(int i = 0; i < N - 1; i++) {
            matrices[i].first = arr[i];
            matrices[i].second = arr[i + 1];
        }
        
        memset(dp, -1, sizeof(dp));
        
        int ans = solve(matrices, 0, N - 2);
        
        return ans;
    }
};





// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends