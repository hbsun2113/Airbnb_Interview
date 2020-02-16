#include "bits/stdc++.h"
using namespace std;
// 假设字符串a、b可以进行拼接，那么一定是这样的：
// 把a先进行reverse，然后分为两部分：first和second，只要b和first相等(second自己要是回文串)、或者b和second相等(first自己要是回文串)，那么a、b就可以进行拼接，
// 分别对应了b+second+first(b和first相等)、second+first+b(b和second相等)
// 这个是此题最最重要的部分，我之所以写了这道题目很久，就是一开始没有参悟到这点
// 这是https://leetcode.com/problems/palindrome-pairs/discuss/79195/O(n-*-k2)-java-solution-with-Trie-structure?orderBy=most_votes 里 @wxd_sjtu 说的
// 另外注意还有空字符串需要特殊处理，这个有点恶心，感觉没有必要作为边界case

// 自己总结出来的，并且放到了最高赞discuss的comment里：
// reverse(a)==first+second, so a==second+first
// IF second+first+b IS Palindrome: second==b && first is Palindrome   -> a+b is Palindrome
// IF b+second+first IS Palindrome: first==b  && second is Palindrome  -> b+a is Palindrome

// 二刷的代码：https://leetcode.com/submissions/detail/241587920/
// 三刷的代码，感觉速度还是有点慢：https://leetcode.com/submissions/detail/249652514/
class Node{
public:
    int p; // p是索引
    vector<Node*> next=vector<Node*>(27,nullptr);
    Node(int _p=-1):p(_p){}
};

class Solution {
public:
    set<vector<int>> res;
    vector<int> empty; // 用来保存空串集合
    Node *root=new Node();
    
    // 常规建树，p是索引
    void buildtree(string& s, int p){
        auto cur=root;
        for(auto &c:s){
            if(cur->next[c-'a']==nullptr) cur->next[c-'a']=new Node();
            cur=cur->next[c-'a'];
        }
        cur->p=p;
    }
    
    // 还是flag好用啊，一开始想着通过p的正负号来区分，但是0太特殊了，不好弄，下回也直接flag!
    void add(string &part, int p, bool flag){
        auto cur=root;
        for(int j=0;j<part.size();j++){
            char &c=part[j];
            if(cur->next[c-'a']==nullptr) return;
            cur=cur->next[c-'a'];
        }
        if(cur->p!=-1){
            if(cur->p==abs(p)) return ;
            if(flag) res.insert({p,cur->p});
            else res.insert({cur->p,p});
        } 
    }
    
    // ["ab","a","b"]：
    // aba:是ba找到了a,   ——ab在前，flag=true
    // bab:是ab找到了b,   ——ab在后，flag=false
    void find(string& s, int p){
        for(int i=1;i<=s.size();i++){
            string first=s.substr(0,i);
            string second=s.substr(i);
            if(ischeck(first)) add(second,p,true);
            if(ischeck(second)) add(first,p,false);
        }
    }
    
    // 检查是否是回文
    bool ischeck(string s){
        if(s.size()<=1) return true;
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++,j--;
            }
            else return false;
        }
        return true;
    }
    
    
    // 如果一个字符串是空串，它能且仅能和回文串进行拼接
    // 但如果一个字符串是回文串，它可不仅能和空串进行拼接：s 和 sll。(如果回文串是其他串的字串，也可能和母串进行拼接)
    // 因此我们只能对空串进行特殊处理(不可以把回文串，像空字符串一样单独列出来)
    void palid_and_empty(int p){
        for(const auto &i:empty){
            res.insert({i,p});
            res.insert({p,i});
        }
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(words[i].size()==0) empty.push_back(i);
            else buildtree(words[i],i);
        } 
        
        for(int i=0;i<words.size();i++){
            if(words[i].size()==0) continue;
            string &s=words[i];
            string t(words[i].rbegin(),words[i].rend());
            if(t==s) palid_and_empty(i);
            find(t,i);
        }
        
        return vector<vector<int>>(res.begin(),res.end());
    }
};