class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return nums.erase(unique(nums.begin(),nums.end()),nums.end())-nums.begin();
    }
};
//学习unique的用法：删除相邻的重复元素，其中使用后面的不同元素来代替前面的元素，返回最后一个元素后一个元素的迭代器，这里要把后面的位置删除。