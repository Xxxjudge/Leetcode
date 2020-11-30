class Solution {
public:
    bool backtracking(vector<vector<char>>& board, string word,int i,int j,int length) {
        if(i>=board.size()||j>=board[0].size()||i<0||j<0||board[i][j]!=word[length]) return false;
        if(length==word.size()-1) return true;
        char temp=board[i][j];
        board[i][j]='*';
        bool ans=backtracking(board,word,i+1,j,length+1)||backtracking(board,word,i-1,j,length+1)||backtracking(board,word,i,j+1,length+1)||backtracking(board,word,i,j-1,length+1);
        board[i][j]=temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=word.size();
        for(int i=0;i<board.size();i++) 
            for(int j=0;j<board[0].size();j++) 
                if(backtracking(board,word,i,j,0)) return true;
        
        return false;
    }
};