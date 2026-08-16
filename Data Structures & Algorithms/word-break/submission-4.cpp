class Solution {
public:

  bool solve(int idx,string &s,unordered_set<string>&st,vector<int>&dp){
        
        int n = s.length();
        
        if(idx==n) return true;

        if(dp[idx]!=-1) return dp[idx];

        for(auto curr:st){
          
         if(curr.length()+idx > n || s.substr(idx,curr.length())!=curr) continue;
            if(solve(idx+curr.length(),s,st,dp)){
              dp[idx]=true;
              return true;
            } 
          
        }

        return dp[idx]=false;
  }

    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.length();

        //for O(1) Lookups
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<int>dp(n,-1);
        return solve(0,s,st,dp);
        
    }
};
