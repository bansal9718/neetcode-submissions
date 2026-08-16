class Solution {
public:

bool dfs(int idx,vector<int>& matchsticks, vector<int>& sides,int length){

        if(idx==matchsticks.size()) return true;

        for(int j=0;j<4;j++){
            if(matchsticks[idx]+sides[j]<=length){
                sides[j]+=matchsticks[idx];
                if(dfs(idx+1,matchsticks,sides,length)){
                    return true;
                }
                sides[j]-=matchsticks[idx];
            }
            if(sides[j]==0) break;
        }
        return false;
}
    bool makesquare(vector<int>& matchsticks) {
        
        int totalSum = accumulate(matchsticks.begin(), matchsticks.end(), 0);        

        //Base Case to form a square
        if(totalSum%4!=0) return false;

        //totalSum =16 , Side = 4
        int requiredSideLength = totalSum/4;
        vector<int>sides(4,0);

        return dfs(0,matchsticks,sides,requiredSideLength);




    }
};