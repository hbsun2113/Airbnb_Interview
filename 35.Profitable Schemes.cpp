#include"bits/stdc++.h"
using namespace std;
class Solution {
public:
    const long long MOD=1e9+7;
    // https://leetcode.com/problems/profitable-schemes/description/
    // 错误示范，虽然还没有想明白为什么错了
    int profitableSchemes0(int G, int P, vector<int>& group, vector<int>& profit) {
        int n=group.size();
        vector<vector<int>> dp(n+1,vector<int>(G+1,-1)); // dp[i][j]代表在前i个组中，有G个人时，能拿到的收益
        
        // for(int i=0;i<=G;i++) dp[0][i]=0;
        dp[0][0]=0;
        
        int res=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=G;j++){
                if(j<group[i-1]) dp[i][j]=dp[i-1][j];
                else{
                    if(dp[i-1][j-group[i-1]]==-1) continue;
                    dp[i][j]=dp[i-1][j-group[i-1]]+profit[i-1];
                    if(dp[i][j]>=P){
                        cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                        res++;
                        //res%=MOD;
                    }
                }
            }
        }
        
        return res;
    }
    
    // lee:
    // https://leetcode.com/problems/profitable-schemes/discuss/154617/C++JavaPython-DP
    // https://leetcode.com/problems/profitable-schemes/discuss/157099/Java-original-3d-to-2d-DP-solution
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        int n=group.size();
        vector<vector<int>> dp(P+1,vector<int>(G+1,0)); // dp[i][j]代表profit是i,并且人数是j时，的方案数目
        
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int p=P;p>=0;p--){
                for(int g=G-group[i];g>=0;g--){
                    dp[min(p+profit[i],P)][g+group[i]]=(dp[min(p+profit[i],P)][g+group[i]]+dp[p][g])%MOD;
                }
            }
        }
        
        int res=0;
        for(const auto &n:dp[P]) res=(res+n)%MOD;
        return res;
    }
    
    
    
};