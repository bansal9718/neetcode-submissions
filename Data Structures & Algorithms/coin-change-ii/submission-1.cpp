class Solution {
public:
int fn(int idx,vector<int>&coins,int target,vector<vector<int>>&dp){

    int n = coins.size();

    if(idx>=n) return 0;

    if(target==0){
     return 1;
    }

    if(dp[idx][target]!=-1) return dp[idx][target];
   int pick =0,notPick =0;
    
    if(coins[idx]<=target){
        pick = fn(idx,coins,target-coins[idx],dp);
    
}
    notPick = fn(idx+1,coins,target,dp);

    return dp[idx][target] = pick+notPick;

}
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return fn(0,coins,amount,dp);
        
    }
};
