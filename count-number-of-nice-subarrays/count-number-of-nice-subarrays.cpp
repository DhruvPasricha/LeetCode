class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> A;
        
        int i = 0;
        while(i < n and nums[i] % 2 == 0){
            i++;
        }
        A.push_back(i);
        
        while(i < n){
            i++; // skipping odd
            int c = 0;
            while(i < n and nums[i] % 2 == 0) { 
                i++;
                c++;
            }
            A.push_back(c); // count of even numbers
        }

        int ans = 0;
        
        i = 0;
        int j = k;
        
        
        while(j < (int)A.size()){
            ans += (A[i] + 1) * (A[j] + 1);
            i++;
            j++;
        }
        
        return ans;
        
    }
};