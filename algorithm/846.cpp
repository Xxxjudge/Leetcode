class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size()%W!=0) return false;
        if(W==1) return true;
        set<int>s(hand.begin(),hand.end());

        unordered_map<int,int>m;
        for(auto e:hand) m[e]++;
        while(!s.empty()) {
            int a=*(s.begin());
            m[a]--;
            if(m[a]==0) s.erase(a);
            for(int i=1;i<W;i++) {
                if(m[a+i]>0) {
                    m[a+i]--;
                    if(m[a+i]==0) s.erase(a+i);
                }
                else return false;
            }
        }
        return true;
    }
};