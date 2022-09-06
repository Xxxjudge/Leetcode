/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        vector<double> ans;
        while(!que.empty()){
            int n=que.size();
            double sum=0;
            for(int i=0;i<n;i++) {
                TreeNode* temp=que.front();
                que.pop();
                if(temp->left!=NULL) que.push(temp->left);
                if(temp->right!=NULL) que.push(temp->right);
                sum+=temp->val;
            }
            ans.push_back(sum/n);
        }
        return ans;
    }
};
// @lc code=end

