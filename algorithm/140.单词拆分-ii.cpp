/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Trie{
private:
    bool isEnd;
    Trie* next[26];
public:
    Trie(){
        isEnd=false;
        memset(next,0,sizeof(next));
    }
    void insert(string word) {
        Trie* p=this;
        if(word.size()==0||p==NULL) return;
        for(int i=0;i<word.size();i++) {
            if(p->next[word[i]-'a']==NULL) {
                p->next[word[i]-'a']=new Trie();
            }
            p=p->next[word[i]-'a'];
        }
        p->isEnd=true;
    }
    bool search(string word) {
        Trie* p=this;
        if(word.size()==0||p==NULL) return false;
        for(int i=0;i<word.size();i++) {
            if(p->next[word[i]-'a']==NULL) {
                return false;
            }
            p=p->next[word[i]-'a'];
        }
        if(p->isEnd) return true;
        return false;
    }
    void dfs(string s,int pos,vector<bool>& visited,vector<string>& ans) {
        if(pos==s.size()) {
            string temp;
            for(int i=0;i<s.size();i++) {
                temp+=s[i];
                if(visited[i]&&i!=s.size()-1) {
                    temp+=' ';
                }
            }
            ans.push_back(temp);
            return;
        }
        Trie* node=this;
        for(int i=pos;i<s.size();i++) {
            if(node->next[s[i]-'a']!=NULL) {
                node=node->next[s[i]-'a'];
                if(node->isEnd) {
                    visited[i]=true;
                    dfs(s, i + 1, visited, ans);
                    visited[i]=false;
                }
            } else return;
        }

    }
};
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie* root=new Trie();
        for(auto word:wordDict) {
            root->insert(word);
        }
        vector<string> ans;
        vector<bool> visited(s.size(),false);
        root->dfs(s,0,visited,ans);
        return ans;
    }
};

// @lc code=end

