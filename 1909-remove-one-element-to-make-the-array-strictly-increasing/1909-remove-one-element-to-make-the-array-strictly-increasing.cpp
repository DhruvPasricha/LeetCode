class Solution {
    
    bool possible(vector<int> &A, int idx) {
        int prev = INT_MIN;
        int n = A.size();
        for(int i = 0;i < n;i++) {
            if(i == idx) continue;
            if(A[i] <= prev) return false;
            prev = A[i];
        }
        return true;
    }
    
public:
    bool canBeIncreasing(vector<int>& nums) {
        
        int n = nums.size();
        int choice1 = -1;
        int choice2 = -1;
        for(int i = 1;i < n;i++) {
            
            if(nums[i] <= nums[i - 1]) {
                choice1 = i - 1;
                choice2 = i;
                break;
            }
        }
        return possible(nums, choice1) or possible(nums, choice2);
    }
};
