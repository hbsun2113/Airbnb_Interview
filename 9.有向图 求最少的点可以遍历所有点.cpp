#include<bits/stdc++.h>

using namespace std;
// https://www.1point3acres.com/bbs/thread-212885-1-1.html
//
class Solution {
public:
    unordered_set<int> res;

    void dfs(int root, int n, unordered_map<int,set<int>> &um, unordered_set<int> &vis, unordered_set<int> root_vis){
        if(root_vis.find(n)!=root_vis.end()) return ;
        root_vis.insert(n);
        vis.insert(n);
        for(const auto &v:um[n]){
            if(res.find(v)!=res.end() && v!=root) res.erase(v);
            dfs(root,v,um,vis,root_vis);
        }
    }


    void traverse(vector<vector<int>> &edges) {
        unordered_map<int,set<int>> um;
        for(auto &v:edges){
            int src=v[0];
            int dsc=v[1];
            um[src].insert(dsc);
        }

        unordered_set<int> vis;

        for(auto &n:um){
            if(vis.find(n.first)!=vis.end()) continue; // 这个可别忘了，避免了明明去除了，然后又加回来的现象
            unordered_set<int> root_vis; // 设立它而不能使用vis的原因，是希望每个节点能够尽可能地探索
            res.insert(n.first);
            dfs(n.first,n.first,um,vis,root_vis);
        }
    }


};

int main() {
    Solution s;
//    vector<vector<int>> edges={{0,1},{1,0},{3,1},{3,2},{2,1}};
//  vector<vector<int>> edges = {{0, 1},
//                               {1, 0},
//                               //{2, 1},
//                               {3, 2},
//                               {2, 3}};
    vector<vector<int>> edges = {{2,9},{3,3},{3,5},{3,7},{4,8},{5,8},{6,6},{7,4},{8,7},{9,3},{9,6}};
    s.traverse(edges);
    for(const auto &n:s.res) cout<<n<<" ";
    cout<<endl;

    return 0;


}