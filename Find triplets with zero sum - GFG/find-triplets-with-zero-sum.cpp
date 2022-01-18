// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

 // } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    
    int countPairs(int arr[], int start, int end, int target) {
    
    int ans = 0;
    
    while(start < end) {
        
        int sum = arr[start] + arr[end];
        
        if(sum == target) {
            
            if(arr[start] == arr[end]) {
                int f = end - start + 1;
                ans += ((f * (f - 1)) / 2);
                break;
            }
            
            int count1 = 0;
            int start_ = start;
            int count2 = 0;
            int end_ = end;
            
            while(start_ < end and arr[start] == arr[start_])
                start_++, count1++;
                
            while(end >= start_ and arr[end] == arr[end_])
                end_--,count2++;
            
            
            ans += count1 * count2;
            
            start = start_;
            end = end_;
            
        } else if(sum < target) {
            start++;
        } else{
            end--;
        }
    }
    return ans;
}

int findTriplets_(int arr[], int n)
{ 
    // brute force O(n^3) O(1)
    // fix one and then two pointer
    
    sort(arr, arr + n);
    int ans = 0;
    for(int i = 0;i < n;i++) {
        ans += countPairs(arr, i + 1, n - 1, -arr[i]);
        if(ans > 0) return 1;
    }
    return ans;
    
}
    
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        
        return findTriplets_(arr, n) > 0;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}  // } Driver Code Ends