#include<bits/stdc++.h>
using namespace std;

int seek(string &s){
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') return i;
    }
    return -1;
}

string slidingPuzzle(vector<vector<int>>& board) {
    string target="123450";
    vector<vector<int>> change{{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
    vector<vector<string>> action{{"R","D"},{"L","R","D"},{"L","D"},{"U","R"},{"U","L","R"},{"U","L"}};
    unordered_set<string> vis;
    string cur="";
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            cur+=to_string(board[i][j]);
        }
    }
    if(cur==target) return 0;

    vis.insert(cur);
    queue<pair<string,string>> q;
    q.push({cur,""});
    int res=0;
    while(!q.empty()){
        for(int i=q.size()-1;i>=0;i--){
            auto t=q.front();
            // cout<<t<<endl;
            if(t.first==target) return t.second;
            q.pop();
            int pos=seek(t.first);
            for(int k=0;k<change[pos].size();k++){
                const auto j=change[pos][k];
                auto w=t.first;
                swap(w[pos],w[j]);
                if(vis.find(w)!=vis.end()) continue;
                vis.insert(w);
                string act=t.second;
                q.push({w,act+action[pos][k]});
            }
        }
        res++;
    }
    return "can not arrive";
}



int main(){
//    vector<vector<int>> board={{1,2,3},{4,0,5}};
//    vector<vector<int>> board={{1,2,3},{5,4,0}};
    vector<vector<int>> board={{4,1,2},{5,0,3}};
    cout<<slidingPuzzle(board)<<endl;
    return 0;
}