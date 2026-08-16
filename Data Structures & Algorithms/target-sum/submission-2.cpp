class Solution {
public:
    int fn(int idx, int currSum, vector<int>& nums, int target, vector<vector<int>>& dp, int offset) {
        if (idx == nums.size()) {
            return currSum == target ? 1 : 0;
        }

        if (dp[idx][currSum + offset] != -1) {
            return dp[idx][currSum + offset];
        }

        int add = fn(idx + 1, currSum + nums[idx], nums, target, dp, offset);
        int subtract = fn(idx + 1, currSum - nums[idx], nums, target, dp, offset);

        return dp[idx][currSum + offset] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        if (abs(target) > totalSum) return 0;

        int offset = totalSum;
        vector<vector<int>> dp(nums.size(), vector<int>(2 * totalSum + 1, -1));

        return fn(0, 0, nums, target, dp, offset);
    }
};
