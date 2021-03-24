class Solution {
public:
    bool check(TreeNode* p,TreeNode* q) {
        if(p==NULL&&q==NULL) return true;
        if(p==NULL||q==NULL) return false;
        return p->val==q->val&&check(p->left,q->right)&&check(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }
};