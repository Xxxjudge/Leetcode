class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //思路，首先进行排序，排序似乎不要求稳定，所以选择时间复杂度最低地堆排序
        //堆排序每次选出最小值，将其放在末尾，并对剩余的数继续进行选取
        int temp=0;
        for(int j=nums.size()-1;j>=1;j--)
        {
            for(int i=(j-1)/2;i>=0;i--)
            {
                if(nums[i]>nums[2*i+1])
                {
                    temp=nums[i];
                    nums[i]=nums[2*i+1];
                    nums[2*i+1]=temp;
                }
                if((2*i+2<=j)&&nums[i]>nums[2*i+2])
                {
                    temp=nums[i];
                    nums[i]=nums[2*i+2];
                    nums[2*i+2]=temp;
                }
            }
            temp=nums[0];
            nums[0]=nums[j];
            nums[j]=temp;
        }
        
        return nums[k-1];
    }
};
//可直接使用sort(nums.begin(),nums.end());
//                 return nums[nums.size()-k];