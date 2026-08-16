class Solution {
public:
   
   void fn(int idx,vector<int>& candidates,vector<int>&curr,set<vector<int>>&res,int target){

   int n = candidates.size();

    if(target==0) {
        res.insert(curr);
        return;
    }

    if(idx==n || target<0) return;

     if(candidates[idx]<=target){
        curr.push_back(candidates[idx]);
        fn(idx+1,candidates,curr,res,target-candidates[idx]);
        curr.pop_back();
     }
      fn(idx+1,candidates,curr,res,target);

   }
   
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

       
        sort(candidates.begin(),candidates.end()); 
        vector<int>curr;
        set<vector<int>>res;
        
        fn(0,candidates,curr,res,target);
        vector<vector<int>>ans(res.begin(),res.end());
        return ans;
    }
};
