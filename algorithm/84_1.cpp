class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0) return 0;
        int ans=0;
        int n=heights.size();
        stack<int> st;
        heights.push_back(-1);
        for(int i=0;i<=n;i++) {
            while(!st.empty()&&heights[i]<heights[st.top()]) {
                int top=st.top();
                st.pop();
                ans=max(ans,st.empty()?i*heights[top]:heights[top]*(i-st.top()-1));
            }
            st.push(i);
        }
        return ans;
    }
};