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
    int fun(TreeNode* root,int& ans) {
        if(root==NULL) return 0;
        int leftval=fun(root->left,ans);
        int rightval=fun(root->right,ans);
        int temp=max(leftval+root->val,rightval+root->val);        
        temp=max(temp,root->val);
        ans=max(ans,leftval+root->val+rightval);
        return max(temp,0);
    }
    int maxPathSum(TreeNode* root) {
        int ans=root->val;
        fun(root,ans);
        return ans;
    }
};