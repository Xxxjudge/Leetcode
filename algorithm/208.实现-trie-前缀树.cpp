/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
private:
    struct TreeNode{
        char value;
        // TreeNode* next[26]={NULL};
        unordered_map<char,TreeNode*> next;
        int count=0;
        int prefix=0;
    };
public:
    TreeNode* root;
    Trie() {
        root = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode* p=root;
        if(word.size()==0||root==NULL) return;
        for(int i=0;i<word.size();i++) {
            if(p->next.find(word[i])==p->next.end()) {
                p->next[word[i]]=new TreeNode();
                p->next[word[i]]->value=word[i];
            }
            p=p->next[word[i]];
            p->prefix++;
        }
        p->count++;
    }
    
    bool search(string word) {
        TreeNode* p=root;
        if(word.size()==0||root==NULL) return false;
        for(int i=0;i<word.size();i++) {
            if(p->next.find(word[i])==p->next.end()) {
                return false;
            }
            p=p->next[word[i]];
            // root->prefix++;
        }
        // root->count++;
        if(p->count>=1) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TreeNode* p=root;
        if(prefix.size()==0||root==NULL) return false;
        for(int i=0;i<prefix.size();i++) {
            if(p->next.find(prefix[i])==p->next.end()) {
                return false;
            }
            p=p->next[prefix[i]];
            // root->prefix++;
        }
        return true;
    }
};



/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

