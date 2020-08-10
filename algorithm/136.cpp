class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single=0;
        for(int num:nums) {
            single^=num;
        }
        return single;
    }
};
/*异或满足交换律，结合律
  a^0=a a^a=0
*/