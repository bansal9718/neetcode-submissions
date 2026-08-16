class Solution {
public:
    bool checkValidString(string s) {
        
        int n = s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return fn(0, 0, s,dp);
    }

    bool fn(int idx,int open, const string&s,vector<vector<int>>&dp){

        if(open<0) return false;
        if(idx==s.size()) return open==0;

        if(dp[idx][open]!=-1) return dp[idx][open];

        bool res=false;

        if(s[idx]=='('){
            res = fn(idx+1,open+1,s,dp);
        }else if(s[idx]==')'){
            res=fn(idx+1,open-1,s,dp);
        }else{
            res = (fn(idx+1,open+1,s,dp) || fn(idx+1,open-1,s,dp) || fn(idx+1,open,s,dp));
        }

        dp[idx][open] =res ?1:0;
        return res;
    }
};
