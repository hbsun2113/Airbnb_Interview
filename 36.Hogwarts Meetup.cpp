#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000000007;
/*
10
1 2 3
8 6 4
7 8 3
8 1
6
8 7
9 4
4 6
1
1 4
 */
int main(){
  int n;
  cin>>n;
  string s;
  getline(cin,s);
  unordered_map<int,vector<int>> um;
  unordered_map<int,string> path;
  vector<int> vec(n,INT_MAX);
  vec[0]=0;
  for(int i=0;i<n;i++){
    getline(cin,s);
    istringstream ins(s);
    string t;
    while(getline(ins,t,' '))
      um[i].push_back(stoi(t));
  }

  queue<vector<int>> q;
  q.push({0,0});

  while(!q.empty()){
    auto t=q.front();
    q.pop();
    for(const auto &i:um[t[0]]){
      auto tmp=t[1]+(i-t[0])*(i-t[0]);
      if(t[0]==0) tmp=t[1];
      if(tmp>=vec[i]) continue;
      vec[i]=tmp;
      q.push({i,vec[i]});
      path[i]=path[t[0]]+to_string(t[0]);
//      cout<<i<<" "<<path[i]<<endl;
    }
  }
  cout<<vec.back()<<": "<<path[n-1]+to_string(n-1)<<endl;
}