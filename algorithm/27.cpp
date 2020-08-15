class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        for(auto it=nums.begin();it!=nums.end();it++) {
            if(*it==val) {
                nums.erase(it);
                it--;
            }
        }
        return nums.size();
    }
};
//迭代器的使用，这里注意执行nums.erase(it)的时候，it会指向后面一个元素，所以在循环里面要--。