class Solution {
public:
void fn(int idx, vector<int>& nums,vector<int>&curr,vector<vector<int>>&res,int target){

int n = nums.size();
  

     if(target==0){
       res.push_back(curr);
       return;
    
}

if(idx ==n || target<0) return;
  
    
    if(nums[idx]<=target){
        curr.push_back(nums[idx]);
         fn(idx,nums,curr,res,target-nums[idx]);
         curr.pop_back();
         
        }
        
       fn(idx+1,nums,curr,res,target);

}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>curr;
        fn(0,nums,curr,res,target);
        return res;

    }
};
