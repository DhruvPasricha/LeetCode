class Solution {
    
    inline int Ceil(int num, int den)  {
        return (num / den) + (num % den != 0);
    }

    bool good(vector<int> &piles, int k, int h)  {
        
        int hoursReq = 0;
        
        for(int &pile : piles) {
            hoursReq += Ceil(pile, k);    
        }
        
        return hoursReq <= h;
    }
    
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 0;
        int r = *max_element(piles.begin(), piles.end());
        
        while(r - l > 1) {
            
            int m = (l + r) >> 1;
            
            if(good(piles, m, h))
                r = m;
            else
                l = m;
        }
        
        return r;
    }
};