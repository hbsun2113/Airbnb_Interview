#include<unistd.h>
#include<stack>
#include"bits/stdc++.h"
using namespace std;



class Solution{

 public:
  int wizards(vector<vector<int>> &vec, int src, int dst){
    if(src==dst) return 0;
    unordered_map<int,vector<int>> um;
    for(int i=0;i<vec.size();i++){
      auto &v=vec[i];
      for(const auto &j:v)
        um[i].push_back(j);
    }

    queue<pair<int,int>> q;
    q.push({src,0});
    vector<int> res(vec.size(),INT_MAX);
    res[src]=0;

    while(!q.empty()){
        auto t=q.front();
        q.pop();
        for(const auto j:um[t.first]){
            int dis=t.second+(j-t.first)*(j-t.first);
            if(res[j]>dis){
                res[j]=dis;
                q.push({j,res[j]});
            }
        }
    }

    return res[dst];
  }
};

int main() {
  Solution solution;
//  vector<vector<int>> vec={{1, 5, 9}, {2, 3, 9}, {4}, {}, {}, {9}, {}, {}, {}, {}};
  vector<vector<int>> vec={{1, 4, 5}, {}, {}, {}, {9}, {}, {}, {}, {}, {}};
  for(int i=0;i<=9;i++)
    cout<<solution.wizards(vec,0,i)<<endl;
  return 0;
}