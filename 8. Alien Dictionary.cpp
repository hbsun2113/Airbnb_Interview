#include"bits/stdc++.h"
using namespace std;
class Solution {
public:
    // 二刷
    // 一刷地址：https://leetcode.com/submissions/detail/239267576/
    unordered_map<char,unordered_set<char>> out;
    unordered_set<char> dict;
    unordered_map<char,int> in_degree;
    string alienOrder(vector<string>& words) {
        string res="";
        if(words.size()==0) return res;
        builddict(words);
        
        for(int i=1;i<words.size();i++){
            string &a=words[i-1];
            string &b=words[i];
            buildgraph(a,b);
        }
        
        unordered_set<char> seed;
        queue<char> q;
        for(auto c:dict){
            if(in_degree[c]==0){
                seed.insert(c);
                q.push(c);
                res+=c;  
                // dict.erase(c); // 易错点：注意不可以在这里dict.erase(c);
            }
        }
        cout<<"erase 1 finish"<<endl;
        
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            dict.erase(t);
            for(const auto &c:out[t]){
                if(--in_degree[c]==0){
                    cout<<t<<" "<<c<<endl;
                    q.push(c);
                    res+=c;
                    dict.erase(c);
                }
            }
        }
        
        if(dict.size()!=0) return "";
        else return res;
        
    }
    
    void builddict(vector<string>& words){
        for(const auto &w:words)
            for(const auto &c:w) 
                dict.insert(c);
    }
    
    void buildgraph(string &a, string &b){
        int i,j;
        for(i=0,j=0;i<a.size() && j<b.size();i++,j++){
            if(a[i]!=b[j]) break;
        }
        if(i<a.size() && j<b.size()){
            if(out[a[i]].find(b[j])==out[a[i]].end()){ // 易错点：注意不可以重复添加
                out[a[i]].insert(b[j]);
                in_degree[b[j]]++;
            } 
        }
    }
    

    
    
};