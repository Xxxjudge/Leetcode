/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* mybuildTree(vector<int>& preorder, vector<int>& inorder,int pl,int pr,int il,int ir) {
        if(pl>pr) return NULL;
        TreeNode* root=new TreeNode(preorder[pl]);
        int llength=mymap[preorder[pl]]-il;
        root->left=mybuildTree(preorder,inorder,pl+1,pl+llength,il,mymap[preorder[pl]]-1);
        int rlength=ir-mymap[preorder[pl]];
        root->right=mybuildTree(preorder,inorder,pr-rlength+1,pr,mymap[preorder[pl]]+1,ir);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++) {
            mymap.insert({inorder[i],i});
        }

        return mybuildTree(preorder,inorder,0,inorder.size()-1,0,inorder.size()-1);


    }
};
// @lc code=end

