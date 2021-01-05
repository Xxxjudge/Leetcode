class Solution {
public:
    vector<int> ans;
    void preOrder(TreeNode* root) {
        if(!root) return;
        else {
            ans.push_back(root->val);
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return ans;
    }
};