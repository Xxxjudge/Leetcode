class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        DFS(image,sr,sc,image[sr][sc]);
        for(int i=0;i<image.size();i++)
        for(int j=0;j<image[0].size();j++)
        if(image[i][j]==-1) image[i][j]=newColor;
        return image;
    }
    void DFS(vector<vector<int>>& image, int sr, int sc, int value) {
        if(sr<0||sr>=image.size()||sc<0||sc>=image[0].size()||value!=image[sr][sc]) return;
        image[sr][sc]=-1;
        DFS(image,sr+1,sc,value);
        DFS(image,sr,sc+1,value);
        DFS(image,sr-1,sc,value);
        DFS(image,sr,sc-1,value);
    }
};
//深度遍历算法，考虑其他方法