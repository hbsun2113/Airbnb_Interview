
#include<bits/stdc++.h>

using namespace std;

vector<string> buddy_list1(int max, vector<vector<string>> vec, vector<string> mylist){
    unordered_set<string> us(mylist.begin(),mylist.end());
    vector<pair<double,int>> um;
    for(int i=0;i<vec.size();i++){
        const auto &v=vec[i];
        int size=v.size();
        int cnt=0;
        for(const auto &c:v){
            if(us.find(c)!=us.end()) cnt++;
        }
        um.push_back({double(cnt)/size,i});
//        cout<<um.back().first<<" "<<um.back().second<<endl;
    }
    auto cmp=[](pair<double,int> &a, pair<double,int> &b){
        return a.first>b.first;
    };
    sort(um.begin(),um.end(),cmp);
    set<string> vis;
    vector<string> res;

    int i=0;
    while(vis.size()<max && i<vec.size()){
        vector<string> &v=vec[um[i].second];
        int j=0;
        while(j<v.size() && vis.size()<max){
            if(us.find(v[j])==us.end() && vis.find(v[j])==vis.end()){
//                cout<<um[i].second<<" "<<v[j]<<endl;
                vis.insert(v[j]);
                res.push_back(v[j]);
            }
            j++;
        }
        i++;
    }

    return res;

}

// 二刷
vector<string> buddy_list(int max, vector<vector<string>> vec, vector<string> mylist){
    vector<pair<double,int>> um;
    unordered_set<string> us(mylist.begin(),mylist.end());
    int n=vec.size();
    for(int i=0;i<n;i++){
        auto &v=vec[i];
        int cnt=0;
        for(const auto &n:v){
            if(us.find(n)!=us.end()) cnt++;
        }
        um.push_back({(double)cnt/(int)v.size(),i});
    }

    auto cmp=[](pair<double,int> &a, pair<double,int> &b){
        return a.first>b.first;
    };
    sort(um.begin(),um.end(),cmp);

    vector<string> res;
    unordered_set<string> vis;
    int i=0;
    while(res.size()<max && i<vec.size()){
        auto &v=vec[um[i].second];
        int j=0;
        while(j<v.size() && res.size()<max){
            if(vis.find(v[j])!=vis.end()) continue;
            vis.insert(v[j]);
            res.push_back(v[j]);
            j++;
        }
        i++;
    }

    return res;
}
int main(){
    vector<string> mylist={"a","b","c","d"};
    vector<vector<string>> vec;
    vec.push_back({"a","b","e","f"});
    vec.push_back({"a","c","d","g"});
//    auto res=buddy_list(10,vec,mylist);
    auto res=buddy_list(2,vec,mylist);
    for(const auto &v:res)
        cout<<v<<" ";
    cout<<endl;
    return 0;
}