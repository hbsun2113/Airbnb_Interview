#include"bits/stdc++.h"
using namespace std;
// https://leetcode.com/problems/pyramid-transition-matrix/description/
class Solution {
public:
    /*
    三刷
    unordered_map<string,vector<char>> um;
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(auto &w:allowed){
            string pre=w.substr(0,2);
            char c=w[2];
            um[pre].push_back(c);
        }
        return dfs(bottom,"",0);
    }
    
    bool dfs(string bottom, string cur, int i){
        if(bottom.size()==1) return true;
        if(i==bottom.size()-1) return dfs(cur,"",0);
        string w=bottom.substr(i,2);
        for(const auto &c:um[w]){
            if(dfs(bottom,cur+c,i+1)) return true;
        }
        return false;
    }
    */
    
    
    // 二刷
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        return dfs(bottom,0,"",allowed);
    }
    
    
    bool dfs(string b, int i, string tmp, vector<string>& allowed){
        if(b.size()==1) return true;
        if(i==b.size()-1 && dfs(tmp,0,"",allowed)) return true;
        for(const auto &a:allowed){
            if(i+1<b.size() && b[i]==a[0] && b[i+1]==a[1] && dfs(b,i+1,tmp+a[2],allowed)) return true;
        }
        return false;
    }
    
    
    // 自己写的，一把过！
    unordered_map<string,vector<string>> um;
    bool pyramidTransition1(string bottom, vector<string>& allowed) {
        for(const auto& a:allowed)
            um[a.substr(0,2)].push_back(a.substr(2));
        return dfs1(bottom,0,"");
    }
    
    
    // bottom是当前的底，index是bottom的索引，part是正在构建的新底
    bool dfs1(string bottom,int index,string part){
        if(bottom.size()<=1) return true;
        if(index==bottom.size()-1){
            string tmp;
            return dfs1(part,0,tmp);
        }
        string key=bottom.substr(index,2);
        auto it=um.find(key);
        if(it==um.end()) return false;
        for(auto &val:um[key]){
            if(dfs1(bottom,index+1,part+val)) return true;
        }
        return false;
    }
    
    
    
    
};