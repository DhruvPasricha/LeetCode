class Solution {
    
    int getMSB(int64_t x) {
        for(int i = 0;i < 5;i++) x |= (x >> (1 << i));
        x += 1;
        return x >> 1;
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
