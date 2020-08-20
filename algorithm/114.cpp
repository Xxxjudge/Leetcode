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
    void flatten(TreeNode* root) {
        vector<TreeNode*> temp;
        preorderTree(root,temp);
        for(int i=1;i<temp.size();i++) {
            temp[i-1]->left=NULL;
            temp[i-1]->right=temp[i];
        }

    }
    void preorderTree(TreeNode* root,vector<TreeNode*>& temp) {
        if(root!=NULL){
            temp.push_back(root);
            preorderTree(root->left,temp);
            preorderTree(root->right,temp);
        }
    }


};