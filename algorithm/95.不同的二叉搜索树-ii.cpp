/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
vector<TreeNode*> generateTree(int begin,int end) {
        if(begin>end) {
            return {nullptr};
        }
        vector<TreeNode*> ans;
        
        for(int i=begin;i<=end;i++) {
            
            vector<TreeNode*> leftTree=generateTree(begin,i-1);
            vector<TreeNode*> rightTree=generateTree(i+1,end);
            for(auto left:leftTree) {
                for(auto right:rightTree) {
                    TreeNode* root=new TreeNode(i);
                    root->left=left;
                    root->right=right;
                    ans.push_back(root);
                }
            }
        }
          
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        return generateTree(1,n);
    }
};
// @lc code=end

