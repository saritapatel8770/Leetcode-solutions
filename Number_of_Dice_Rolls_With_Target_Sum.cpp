#define M 1000000007
class Solution {
public:
    long long int solve(int n, int k, int x, vector<vector<long long int>>& dp){
        if(x<0) return 0;
        if(n==0 && x!=0) return 0;
        if(n!=0 && x==0) return 0;
        if(n==0 && x==0) return 1;
        if(dp[n][x]!=-1) return dp[n][x];
        long long int ans=0;
        for(int i=1 ; i<=k ; i++){
            ans+=(solve(n-1, k, x-i, dp)%M);
        }
        return dp[n][x]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long int>> dp(n+1, vector<long long int>(target+1, -1));
        long long int ans=solve(n,k,target,dp);
        return ans%M;
    }
};
