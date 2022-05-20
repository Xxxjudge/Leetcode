/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    void dfs(vector<vector<int>>& ans,vector<int>& temp,TreeNode* root,int sum,int targetSum) {
        if(sum==targetSum&&root->left==NULL&&root->right==NULL) {
            ans.push_back(temp);
            return;
        }
        if(root->left!=NULL) {
            temp.push_back(root->left->val);
            dfs(ans,temp,root->left,sum+root->left->val,targetSum);
            temp.pop_back();
        }
        if(root->right!=NULL) {
            temp.push_back(root->right->val);
            dfs(ans,temp,root->right,sum+root->right->val,targetSum);
            temp.pop_back();
       }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        if(root==NULL) return ans;
        temp.push_back(root->val);
        dfs(ans,temp,root,root->val,targetSum);
        return ans;
    }
};
// @lc code=end

