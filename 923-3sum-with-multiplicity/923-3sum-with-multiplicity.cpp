class Solution {
    
    const int64_t mod = 1e9 + 7;
    
    int64_t countPairs(vector<int> &arr, int start, int target) {
        
        int end = arr.size() - 1;
        int64_t ans = 0;
        
        while(start < end) {
            
            int sum = arr[start] + arr[end];
            
            if(sum == target) {
                
                if(arr[start] == arr[end]) {
                    
                    int64_t f = end - start + 1;
                    ans = (ans + (f * (f - 1)) / 2) % mod;
                    return ans;
                }
                
                int64_t f1 = 0;
                int64_t f2 = 0;
                
                int start_ = start;
                int end_ = end;
                
                while(start_ < end and arr[start] == arr[start_])
                    f1++, start_++;
                
                while(end_ > start and arr[end] == arr[end_])
                    f2++, end_--;
                
                ans = (ans + f1 * f2) % mod;
                
                start = start_;
                end = end_;
                
            } else if(sum > target) {
                
                end--;
                
            } else {
                
                start++;
            }
            
        }
        
        return ans;
    }
    
    
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        sort(arr.begin(), arr.end());
        
        int64_t ans = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            ans = (ans + countPairs(arr, i + 1, target - arr[i])) % mod;
        }
        
        return ans;
    }
};