class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans; 
        queue<TreeNode*> myQue;
        myQue.push(root);
        while(!myQue.empty()) {
            int n=myQue.size();
            for(int i=0;i<n;i++) {
                TreeNode* temp=myQue.front();
                myQue.pop();
                if(temp->left) myQue.push(temp->left);
                if(temp->right) myQue.push(temp->right);
                if(i==n-1) ans.push_back(temp->val);
            }           
        }
        return ans;
    }
};
//二叉树右视图，采取层次遍历，选择每层最右边的值