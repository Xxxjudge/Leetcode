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
    vector<int> temp;
    void sortOrder(TreeNode* root,vector<int>& temp) {
        if(root!=nullptr) {
            temp.push_back(root->val);
            sortOrder(root->left,temp);
            sortOrder(root->right,temp);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        sortOrder(root,temp);
        sort(temp.begin(),temp.end());
        return temp[k-1];
    }
};//先遍历后排序,不行,这是个二叉搜索树