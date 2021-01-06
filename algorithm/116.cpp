class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> myQue;
        if(!root) return NULL;
        myQue.push(root);
        while(!myQue.empty()) {
            Node* temp;
            int n=myQue.size();
            for(int i=0;i<n;i++) {
                temp=myQue.front();
                myQue.pop();
                if(i==n-1) temp->next=NULL;
                else temp->next=myQue.front();
                if(temp->left) {
                    myQue.push(temp->left);
                    myQue.push(temp->right);
                }
            }
        }
        return root;
    }
};