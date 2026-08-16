class Solution {
public:
    unordered_map<int, int> indices;

    TreeNode* dfs(int preorderStart, int inorderStart, int size, vector<int>& preorder, vector<int>& inorder) {
        if (size <= 0) return nullptr;

        int root_val = preorder[preorderStart];
        int inorderIndex = indices[root_val];

        int leftSize = inorderIndex - inorderStart;

        TreeNode* leftChild = dfs(preorderStart + 1, inorderStart, leftSize, preorder, inorder);
        TreeNode* rightChild = dfs(preorderStart + 1 + leftSize, inorderIndex + 1, size - 1 - leftSize, preorder, inorder);

        return new TreeNode(root_val, leftChild, rightChild);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            indices[inorder[i]] = i;
        }
        return dfs(0, 0, preorder.size(), preorder, inorder);
    }
};
