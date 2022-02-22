// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    
    int dp[101][101];
    
    int solve(int A[], int left, int right) {
        
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
            
            int cur = leftAns + rightAns + (A[left] * A[k + 1] * A[right + 1]);
            
            ans = min(ans, cur);
            
        }
        
        
        return ans;
        
        
    }
    
    
public:
    int matrixMultiplication(int N, int arr[])
    {

        memset(dp, -1, sizeof(dp));
        
        int ans = solve(arr, 0, N - 2);
        
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