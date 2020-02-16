#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<int> res;
  vector<vector<int>> vec = {{3, 5, 7, 9}, {2, 3, 8}, {5, 8},{6}};
  unordered_map<int, vector<int>> out; // Ö»ÐèÒª´æ´¢×Ô¼ºÖ¸ÏòË­¾Í¿ÉÒÔÁË
  unordered_map<int, int> in_degree;
  for (auto &v:vec) {
    if(v.size()==1){ // 别忘了单独处理单个元素
      res.push_back(v[0]);
      continue;
    }
    for (int i = 1; i < v.size(); i++) {
//      cout<<v[i-1]<<"->"<<v[i]<<endl;
      out[v[i - 1]].push_back(v[i]);
      in_degree[v[i - 1]] += 0;  // ±ðÍüÁËÕâÐÐ
      in_degree[v[i]]++;  // Ö±½Ó°ÑÈë¶ÈÒ²¸øÍ³¼ÆÁË
    }
  }

  queue<int> q;
  for (auto n:in_degree) {
    if (n.second == 0) {
      q.push(n.first);
      res.push_back(n.first);
    }
  }

  while (!q.empty()) {
    auto &n = q.front();
    q.pop();
    for (auto &t:out[n]) {
      if (--in_degree[t] == 0) {
        res.push_back(t);
        q.push(t);
      }
    }
  }

  for (const auto &n:res) cout << n << " ";
  cout << endl;
  return 0;
}
