class Solution {
public:
    const int64_t  mod = 1e9 + 7;
    int numTilings(int n) {
        int64_t dp[3][2][2];
        
        for(int pos = n;pos >= 0;pos--){
            for(int up = 0;up <= 1;up++){
                for(int down = 0;down <= 1;down++){
                    auto &ans = dp[pos % 3][up][down];
                    if(pos == n){
                        ans = up and down;
                    }else{
                        
                         if(up and down){
                            int64_t ans1 = (pos + 2 <= n) ? dp[(pos + 2) % 3][true][true] : 0;
                            int64_t ans2 = dp[(pos + 1) % 3][true][true];
                            int64_t ans3 = dp[(pos + 1) % 3][false][true];
                            int64_t ans4 = dp[(pos + 1) % 3][true][false];
                            ans = ans1 + ans2 + ans3 + ans4;
                        }else if(up){
                            int64_t ans1 = (pos + 2 <= n) ? dp[(pos + 2) % 3][true][true] : 0;
                            int64_t ans2 = dp[(pos + 1) % 3][true][false];
                            ans = ans1 + ans2;
                        }else if(down){
                            int64_t ans1 = (pos + 2 <= n) ? dp[(pos + 2) % 3][true][true] : 0;
                            int64_t ans2 = dp[(pos + 1) % 3][false][true];
                            ans = ans1 + ans2;
                        } 
                    }
                    ans %= mod;
                }
            }
        }
        return dp[0][1][1];
    }
};