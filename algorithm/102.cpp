class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue <TreeNode*> q;
        TreeNode* a;
        q.push(root);
        while(!q.empty()) {
            int currentLevelSize=q.size();
            vector<int> temp;
            for(int i=0;i<currentLevelSize;i++) {
                a=q.front();
                q.pop();
                temp.push_back(a->val);
                if(a->left!=NULL) q.push(a->left);
                if(a->right!=NULL) q.push(a->right); 
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
//二叉树的层次遍历，用队列实现的版本