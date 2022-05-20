/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    void dfs(int& ans,TreeNode* root,int tempsum) {
        if(root->left==NULL&&root->right==NULL) {
            ans+=tempsum;
            return;
        }
        tempsum=tempsum*10;
        if(root->left!=NULL) {
            tempsum+=root->left->val;
            dfs(ans,root->left,tempsum);
            tempsum-=root->left->val;
        }
        if(root->right!=NULL) {
            tempsum+=root->right->val;
            dfs(ans,root->right,tempsum);
            tempsum-=root->right->val;
        }


    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        if(root==NULL) return 0;
        dfs(ans,root,root->val);
        return ans;
    }
};
// @lc code=end

