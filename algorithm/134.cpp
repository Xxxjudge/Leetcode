class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumG=0,curG=0,st=0;
        for(int i=0;i<gas.size();i++) {
            sumG+=gas[i]-cost[i];
            curG+=gas[i]-cost[i];
            if(curG<0) {
                curG=0;
                st=i+1;
            }
        } 
        if(sumG<0) return -1;
        return st;
    }
};