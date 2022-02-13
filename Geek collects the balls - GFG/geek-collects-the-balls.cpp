// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxBalls(int N, int M, vector<int> a, vector<int> b){
        // code here
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        
        int i = N - 1;
        int j = M - 1;
        
        int next1 = 0;
        int next2 = 0;
        
        while(i >= 0 and j >= 0) {
            
            if(a[i] > b[j]) {
                next1 += a[i];
                i--;
            } else if(a[i] < b[j]) {
                next2 += b[j];
                j--;
            } else{
                
                int cur = a[i];
                int c1 = 0;
                int c2 = 0;
                
                while(i >= 0 and a[i] == cur) 
                    i--, c1++;
                
                while(j >=  0 and b[j] == cur)
                    j--, c2++;
                    
      
                if(c1 >= 2 and c2 >= 2) {
                    
                    int next1_ = 0;
                    int next2_ = 0;
                    
                    // waapis
                    next1_ = cur * (c1 + c2 - 2) + next1;
                    next2_ = cur * (c1 + c2 - 2) + next2;
                    
                    int next1__ = 0;
                    int next2__ = 0;
                    
                    // waapis nhi aaega
                    next1__ = cur * (c1 + c2 - 1) + next2;
                    next2__ = cur * (c1 + c2 - 1) + next1;
                    
                    next1 = max(next1_, next1__);
                    next2 = max(next2_, next2__);
                    
                    
                    
                } else if(c1 >= 2){
                    
                    
                    int next1_ = cur * c1 + max(next1, next2);
                    int next2_ = max((cur * c1) + next1, cur + next2);
                    
                    next1 = next1_;
                    next2 = next2_;
                    
                } else if(c2 >= 2) {
                    
                    int next1_ = max((cur * c2) + next2, cur + next1);
                    int next2_ = cur * c2 + max(next1, next2);
                    
                    next1 = next1_;
                    next2 = next2_;
                    
                    
                } else{
                    
                    int next1_ = cur + max(next1, next2);
                    int next2_ = cur + max(next1, next2);
                    
                    next1 = next1_;
                    next2 = next2_;
                    
                }
            }
        }
        
        while(i >= 0) {
            next1 += a[i];
            i--;
        }
        
        while(j >= 0) {
            next2 += b[j];
            j--;
        }
        
        return max(next1, next2);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M;
        vector<int> a(N), b(M);
        for(int i = 0;i < N;i++)
            cin>>a[i];
        for(int i = 0;i < M;i++)
            cin>>b[i];
        
        Solution ob;
        cout<<ob.maxBalls(N, M, a, b)<<"\n";
    }
    return 0;
}  // } Driver Code Ends