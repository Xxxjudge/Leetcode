/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<char>>& board,int x,int y) {
        if(x<0||x>=board.size()||y<0||y>=board[0].size()||board[x][y]!='O') return;
        board[x][y]='A';
        dfs(board,x,y+1);
        dfs(board,x,y-1);
        dfs(board,x-1,y);
        dfs(board,x+1,y);
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        if(m<=2||n<=2) return;
        for(int i=0;i<m;i++) {
            dfs(board,i,0);
            dfs(board,i,n-1);
        }
        for(int i=0;i<n;i++) {
            dfs(board,0,i);
            dfs(board,m-1,i);
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='A') board[i][j]='O';
        return;
    }
};
// @lc code=end

