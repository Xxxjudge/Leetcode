class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        deque<TreeNode*> q;
        q.push_back(root);
        TreeNode* a;
        bool isOdd=true;
        while(!q.empty()) {
            vector<int> temp;
            int currentLevelSize=q.size();
            for(int i=0;i<currentLevelSize;i++) {
                if(isOdd) {
                    a=q.front();
                    temp.push_back(a->val);
                    q.pop_front();
                    if(a->left) q.push_back(a->left);
                    if(a->right) q.push_back(a->right);
                } else {
                    a=q.back();
                    temp.push_back(a->val);
                    q.pop_back();
                    if(a->right) q.push_front(a->right);
                    if(a->left) q.push_front(a->left);
                }   
            }
            isOdd=!isOdd;
            ans.push_back(temp);
        }
        return ans;
    }
};//锯齿形层次遍历，相比层次遍历，需要用双端队列来维护，一个标志位确定其两种形式，具体情况具体分析！