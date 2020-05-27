// https://leetcode.com/problems/diameter-of-binary-tree/submissions/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
public:
    int solve(TreeNode* root, int &ans){
        if(root==NULL)
            return 0;
        int left = solve(root->left,ans);
        int right = solve(root->right,ans);
        ans = max(left+right,ans);
        return max(left,right)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};
