class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        int total_len=len1+len2;
        int median=total_len/2;
        if(total_len%2==0)
        return (GetKth(nums1,nums2,median+1)+GetKth(nums1,nums2,median))/2;
        else
        return GetKth(nums1,nums2,median+1);
    }
    double GetKth(vector<int>& nums1,vector<int>& nums2,int k)
    {
        int len1=nums1.size();
        int len2=nums2.size();
        int index1=0,index2=0;
        int newindex1,newindex2;
        //边界情况
        while(1)
        {
            if(len1==index1)
            return nums2[k-1+index2];
            if(len2==index2)
            return nums1[k-1+index1];
            if(k==1)
            return min(nums1[index1],nums2[index2]);
            //正常情况
            newindex1=min(len1,index1+k/2)-1;
            newindex2=min(len2,index2+k/2)-1;
            if(nums1[newindex1]<nums2[newindex2])
            {
                k-=newindex1-index1+1;
                index1=newindex1+1;
            }
            else
            {
                k-=newindex2-index2+1;
                index2=newindex2+1;
            }
        }
    }

};