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
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        if(abs(Theight(root->left)-Theight(root->right))<=1&&isBalanced(root->left)&&isBalanced(root->right)) return true;
        else return false;
    }
    int Theight(TreeNode* root) {
        if(root==NULL) return 0;
        else return max(Theight(root->left),Theight(root->right))+1;
    }
};
//平衡二叉树