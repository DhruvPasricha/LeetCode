class Solution {
public:
    // int64_t dp[1000][2][2];
    const int64_t  mod = 1e9 + 7;
    
//     int64_t solve(int pos, bool up, bool down, int n){
        
//         if(pos > n) return 0;
        
//         if(pos == n){
//             return up and down;
//         }
        
//         int64_t &ans = dp[pos][up][down];
        
//         if(ans != -1) return ans;
        
//         if(up and down){
        
//             // _ _
//             // _ _
            
//             int64_t ans1 = solve(pos + 2, true, true, n);

//             // _
//             // _
            
//             int64_t ans2 = solve(pos + 1, true, true, n);


//             // _ _
//             // _
            
//             int64_t ans3 = solve(pos + 1, false, true, n);


//             // _ 
//             // _ _
//             int64_t ans4 = solve(pos + 1, true, false, n);
            
//             ans = ans1 + ans2 + ans3 + ans4;
            
//         }else if(up){
        
        
//             // x  _
//             // _  _
//             int64_t ans1 = solve(pos + 2, true, true, n);
        
//             // x
//             // _ _
//             int64_t ans2 = solve(pos + 1, true, false, n);
            
//             ans = ans1 + ans2;
            
//         }else if(down){
            
//             // _ _
//             //   _
//             int64_t ans1 = solve(pos + 2, true, true, n);
            
//             // _ _
//             // x
//             int64_t ans2 = solve(pos + 1, false, true, n);
            
//             ans = ans1 + ans2;
//         }
        
//         return ans % mod;
//     }
    
    
    int solve(int n){
        
        int64_t dp[3][2][2];
        
        for(int pos = n;pos >= 0;pos--){
            for(int up = 0;up <= 1;up++){
                for(int down = 0;down <= 1;down++){
                    
                    auto &ans = dp[pos % 3][up][down];
                    
                    if(pos == n){
                        ans = up and down;
                    }else{
                        
                         if(up and down){
        
                            // _ _
                            // _ _

                            int64_t ans1 = (pos + 2 <= n) ? dp[(pos + 2) % 3][true][true] : 0;

                            // _
                            // _

                            int64_t ans2 = dp[(pos + 1) % 3][true][true];


                            // _ _
                            // _

                            int64_t ans3 = dp[(pos + 1) % 3][false][true];


                            // _ 
                            // _ _
                            int64_t ans4 = dp[(pos + 1) % 3][true][false];

                            ans = ans1 + ans2 + ans3 + ans4;

                        }else if(up){


                            // x  _
                            // _  _
                            int64_t ans1 = (pos + 2 <= n) ? dp[(pos + 2) % 3][true][true] : 0;

                            // x
                            // _ _
                            int64_t ans2 = dp[(pos + 1) % 3][true][false];

                            ans = ans1 + ans2;

                        }else if(down){

                            // x _
                            // _ _
                            int64_t ans1 = (pos + 2 <= n) ? dp[(pos + 2) % 3][true][true] : 0;

                            // _ _
                            // x
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
    
    
    int numTilings(int n) {
        
        return solve(n);
        
//         memset(dp, -1, sizeof(dp));
        
//         return solve(0, true, true, n);
    }
};