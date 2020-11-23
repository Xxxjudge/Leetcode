class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p=head;
        unordered_set<ListNode*> S;
        while(p!=NULL) {
            if(S.find(p)==S.end()) {
                S.insert(p);
            } else {
                return true;
            }
            p=p->next;
        }
        return false;
    }
};