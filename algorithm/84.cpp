class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        return maxArea(heights,0,heights.size()-1);
    }
    int maxArea(vector<int>& heights,int front,int end) {
        if(front==end) return heights[front];
        if(front>end) return 0;
        int minH=heights[front];
        int distance=end-front+1,minP=front;
        for(int i=front;i<=end;i++) 
            if(heights[i]<minH) {
                minH=heights[i];
                minP=i;
            }
        int area=distance*minH;
        int leftP=minP-1;
        while(leftP>front&&heights[leftP]<=heights[minP]) leftP--;
        int leftarea=maxArea(heights,front,leftP);
        int rightP=minP+1;
        while(rightP<end&&heights[rightP]<=heights[minP]) rightP++;
        int rightarea=maxArea(heights,rightP,end);
        return max(max(leftarea,rightarea),area);
    }

};
//分治法不行！