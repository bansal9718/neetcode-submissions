/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> solve(TreeNode*root){

        if(!root) return {0,0};

        pair<int,int>p1 = solve(root->left);
        pair<int,int>p2 = solve(root->right);

        int pick = root->val + p1.second+p2.second;

        int skip = max(p1.first,p1.second) + max(p2.first,p2.second);

        return {pick,skip};
    }
    int rob(TreeNode* root) {
        
        if(!root) return 0;
        pair<int,int>ans= solve(root);
        return max(ans.first,ans.second);
    }
};