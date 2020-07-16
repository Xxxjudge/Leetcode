class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int i=0,j=height.size()-1;
        while(i<j) {
            ans=(ans<min(height[i],height[j])*(j-i))?min(height[i],height[j])*(j-i):ans;
            if(height[i]<height[j]) i++;
            else j--;
        }
        return ans;
    }
};
//双指针方法，时间很慢，可以改进