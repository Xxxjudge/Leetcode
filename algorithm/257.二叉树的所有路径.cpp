/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void dfs(vector<string>& ans,string temp,TreeNode* root){
        if(root==NULL||root->left==NULL&&root->right==NULL) {
            ans.push_back(temp);
            return;
        }
        if(root->left!=NULL) {
            string a="->"+to_string(root->left->val);
            temp=temp+a;
            dfs(ans,temp,root->left);
            temp=temp.substr(0,temp.size()-a.size());
        }
        if(root->right!=NULL) {
            string a="->"+to_string(root->right->val);
            temp=temp+a;
            dfs(ans,temp,root->right);
            temp=temp.substr(0,temp.size()-a.size());
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp;
        if(root==NULL) return ans;
        temp+=to_string(root->val);
        dfs(ans,temp,root);
        return ans;
        

    }
};
// @lc code=end

