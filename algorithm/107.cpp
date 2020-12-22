class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* a;
        stack<vector<int>> s;
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
            s.push(temp);
        }
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};//二叉树层次遍历的变种，要求自底向上，其实就是调用一个栈，先将结果存入栈内，然后再出栈为答案。