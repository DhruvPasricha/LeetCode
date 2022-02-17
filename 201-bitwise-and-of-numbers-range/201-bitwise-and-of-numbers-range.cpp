class Solution {
    
    int getMSB(int x) {
        
        for(int i = 30;i >= 0;i--) {
            if((1 << i) & x) 
                return 1 << i;
        }
        
        return 0;
        
    }
    
    
    
public:
    int rangeBitwiseAnd(int left, int right) {
        
        if(left == 0)
            return 0;
        
        int msb_left = getMSB(left);
        int msb_right = getMSB(right);
        
        if(msb_left != msb_right)
            return 0;
        
        return msb_left + rangeBitwiseAnd(left - msb_left, right - msb_right);
    }
};
