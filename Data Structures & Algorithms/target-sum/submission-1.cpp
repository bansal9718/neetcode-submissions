class Solution {
public:
int fn(int idx,vector<int>&nums,int target,int &sum){
    
    int n= nums.size();
    

    if(idx==n){
        return sum==target? 1:0;
    }
    
    
    int add = fn(idx+1,nums,sum+nums[idx],target);
    int subtract = fn(idx+1,nums,sum-nums[idx],target);

    return add+subtract;
}
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum =0;
        return fn(0,nums,target,sum);

    }
};
