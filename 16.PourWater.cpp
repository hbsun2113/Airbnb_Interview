#include<unistd.h>
#include<stack>
#include"bits/stdc++.h"
using namespace std;



void draw(vector<int> h, int V, int K, int j=-1) {
    int maxh=4;
    h.insert(h.begin(),maxh);
    h.push_back(maxh);
    int n=h.size();
    vector<vector<char>> vec(maxh,vector<char>(n));
    for(int i=0;i<maxh;i++){
        for(int j=0;j<n;j++){
            if(h[j]>i) vec[i][j]='#';
            else vec[i][j]=' ';
        }
    }
    if(j>=0){
        int res=h[j+1];
        vec[res][j+1]='w';
    }
    reverse(vec.begin(),vec.end());
    for(int i=0;i<maxh;i++){
        for(int j=0;j<n;j++){
            cout<<vec[i][j]<<"";
        }
        cout<<endl;
    }
    cout<<"----------------------"<<endl;
}

vector<int> pourWater(vector<int>& h, const int V, const int K) {
    for(int i=0;i<V;i++){
        int j=K;
        while(j-1>=0 && h[j]>=h[j-1]) j--;
        while(j<K && h[j]==h[j+1]) j++;
        if(j!=K){
            draw(h,V,K,j);
//      h[j]++;
            continue;
        }

        j=K;
        while(j+1<h.size() && h[j+1]<=h[j]) j++;
        while(j>K && h[j]==h[j-1]) j--;
        draw(h,V,K,j);
//        h[j]++;
    }
    return h;
//    return ;
}

int main() {
    vector<int> h={2,1,1,2,1,2,2};
    int V=4,K=3;
    pourWater(h,V,K);
    return 0;
}