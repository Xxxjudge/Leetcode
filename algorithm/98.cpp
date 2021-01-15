class Solution {
public:
    vector<int> temp;
    bool isValidBST(TreeNode* root) {
        midOrder(root);
        for(int i=0;i<temp.size()-1;i++) if(temp[i]>=temp[i+1]) 
        return false;
        return true;

    }
    void midOrder(TreeNode* root) {
        if(root==NULL) return;
        midOrder(root->left);
        temp.push_back(root->val);
        midOrder(root->right);
    }
};