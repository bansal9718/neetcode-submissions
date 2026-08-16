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

 void dfs(TreeNode* root, int &cnt,int maxSoFar) {

      if(!root) return;
      if(root->val >=maxSoFar){
        cnt++;
        maxSoFar = root->val;
      }
    
       dfs(root->left,cnt,maxSoFar);
  
       dfs(root->right,cnt,maxSoFar);
       
       
    
}
    int goodNodes(TreeNode* root) {
        int cnt =0;
        if(!root) return 0;
        
       dfs(root,cnt,root->val);
        return cnt;

        


    }
};
