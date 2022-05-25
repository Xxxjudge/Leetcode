/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
public:
    vector<TreeNode*> in;
    int i,n;
    void inorder(TreeNode* root) {
        if(root!=NULL) {
            inorder(root->left);
            in.push_back(root);
            inorder(root->right);
        }
    }
    BSTIterator(TreeNode* root) {
        in.push_back(new TreeNode(0));
        inorder(root);
        i=0;
        n=in.size();
    }
    
    int next() {
        i++;
        return in[i]->val;
    }
    
    bool hasNext() {
        if(i+1<n) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

