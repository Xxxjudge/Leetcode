/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start
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
        int ans;
        int depth(TreeNode* root) {
            if(root==NULL) return 0;
            int l=depth(root->left);
            int r=depth(root->right);
            ans=max(l+r,ans);
            return max(l,r)+1;
        }

        int diameterOfBinaryTree(TreeNode* root) {
            ans=0;
            depth(root);
            return ans;
        }
};
// @lc code=end

