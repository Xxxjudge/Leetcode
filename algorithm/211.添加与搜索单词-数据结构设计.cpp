/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
class WordDictionary {
private:
    bool isEnd;
    WordDictionary* next[26];
public:
    WordDictionary() {
        isEnd=false;
        memset(next,0,sizeof(next));
    }
    
    void addWord(string word) {
        WordDictionary* p=this;
        if(p==NULL||word.size()==0) return;
        for(int i=0;i<word.size();i++) {
            if(p->next[word[i]-'a']==NULL) {
                p->next[word[i]-'a']=new WordDictionary();
            }
            p=p->next[word[i]-'a'];
        }
        p->isEnd=true;
    }
    bool dfs(int index,string word,int n,WordDictionary* p) {
        if(index==n) {
            if(p->isEnd) return true;
            else return false;
        }
        for(int i=index;i<n;i++) {
            if(word[i]=='.') {
                for(int j=0;j<26;j++) {
                    if(p->next[j]==NULL) continue;
                    else if (dfs(i+1,word,n,p->next[j])) return true;
                }
                return false;
            } else {
                if(p->next[word[i]-'a']==NULL) return false;
                p=p->next[word[i]-'a'];
            }
        }
        if(p->isEnd) return true;
        else return false;
    }

    bool search(string word) {
        return dfs(0,word,word.size(),this);

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

