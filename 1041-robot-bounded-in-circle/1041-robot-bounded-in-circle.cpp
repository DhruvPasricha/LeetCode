class Solution { 
    
    bool inside(int64_t x, int64_t y) {
        return x*x + y*y <= 2000;
    }
    
    
    bool good(int op, string &s) {
        
        int n = s.size();
        int d[4] = {0, 0, 0, 1};
        // east, south, west, north 
        int pos = 0;
        int64_t x = 0;
        int64_t y = 0;
        bool ans = true;
        for(int i = 0;op > 0 and ans;op--, i++) {
            i %= n;
            if(s[i] == 'L') {
                pos--;
            } else if(s[i] == 'R') {
                pos++;
            } else {
                if(pos == 0) {
                    x++;
                } else if(pos == 1) {
                    y--;
                } else if(pos == 2) {
                    x--;
                } else{
                    y++;
                }
                ans &= inside(x, y);
            }
            pos += 4;
            pos %= 4;
        }
        return ans;
    }
    
public:
    bool isRobotBounded(string instructions) {
        
        int l = 0;
        int r = 1e5;
        
        while(r - l > 1) {
            
            int m = (l + r) >> 1;
            if(good(l, instructions)) l = m;
            else r = m;
        }
        return r == 1e5;
    }
};