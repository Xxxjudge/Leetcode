/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    unordered_map<int,int> mymap;
    TreeNode* mybuildTree(vector<int>& inorder, vector<int>& postorder,int il,int ir,int pl,int pr) {
        if(pl>pr) return nullptr;
        TreeNode* root=new TreeNode(postorder[pr]);
        int llength=mymap[postorder[pr]]-il;
        root->left=mybuildTree(inorder,postorder,il,il+llength-1,pl,pl+llength-1);
        int rlength=ir-mymap[postorder[pr]];
        root->right=mybuildTree(inorder,postorder,mymap[postorder[pr]]+1,ir,pl+llength,pr-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++) {
            mymap.insert({inorder[i],i});
        }

        return mybuildTree(inorder,postorder,0,inorder.size()-1,0,inorder.size()-1);

    }
};
// @lc code=end

