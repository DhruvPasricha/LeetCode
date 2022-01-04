class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int ans = 0;
        int i = 0;
        while(n) {
            bool setBit = n & 1;
            if(not setBit) ans += (1 << i);
            i++;
            n >>= 1;
        }
        return ans;
    }
};
