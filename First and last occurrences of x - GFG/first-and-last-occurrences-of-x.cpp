// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

int lowerbound(int *arr, int n, int x) {
    
    
    int l = -1;
    int r = n;
    // leftmost index >= x
    while(r - l > 1) {
        
        int m = (l + r) / 2;
        
        if(arr[m] >= x) r = m;
        else l = m;
        
    }
    return r;
}

vector<int> find(int arr[], int n , int x )
{
    
    int first = lowerbound(arr, n, x);
    if(first == n or arr[first] != x) return {-1, -1};
    int last = lowerbound(arr, n, x + 1) - 1;
    
    return {first, last};
}



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends