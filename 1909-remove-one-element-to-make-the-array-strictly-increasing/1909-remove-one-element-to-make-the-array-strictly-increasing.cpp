class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        
      int n = nums.size(); 
      for(int i = 0;i < n;i++) {
           int prev = INT_MIN;
           bool ok = true;
           for(int j = 0;j < n;j++) {
               if(i == j) continue;
               if(nums[j] <= prev) {
                   ok = false;
                   break;
               }
               prev = nums[j];
          }
          
         if(ok){ 
              cout << "removed" << i << endl;
              return true;
        }
       }
        return false;
    }
};

