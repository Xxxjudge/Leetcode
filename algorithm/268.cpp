class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;
        for(auto x:nums) s.insert(x);
        for(int i=0;i<n;i++) if(s.find(i)==s.end()) return i;
        return n;
    }
};
//哈希表记录元素个数，set和map的区别就是有无索引


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0,numSum=0;
        for(int i=1;i<=n;i++) sum+=i;
        for(auto x:nums) numSum+=x;
        return sum-numSum;
    }
};
//求和相减

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int temp=nums.size();
        for(int i=0;i<nums.size();i++) temp=temp^i^nums[i];
        return temp;
    }
};
//位运算，一个数和两个相同的数位运算之后还是本身