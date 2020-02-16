#include<bits/stdc++.h>

using namespace std;
// https://github.com/allaboutjst/airbnb
//https://www.1point3acres.com/bbs/interview/airbnb-software-engineer-141746.html
// 很常规的BFS吧，感觉难度达不到A家
void paint(vector<string> &m, int x, int y) {
    int row=m.size();
    int col=m[0].size();
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    queue<pair<int,int>> q;
    q.push({x,y});
    m[x][y]='O';
    while(!q.empty()){
        auto t=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int xx=t.first+dx[k];
            int yy=t.second+dy[k];
            if(xx<0 || xx>=row || yy<0 || yy>=col || m[xx][yy]!='W') continue;
            m[xx][yy]='O';
            q.push({xx,yy});
        }
    }

    for(const auto &v:m)
        cout<<v<<endl;
}

int main() {
    vector<string> m={"WWWLLLW",
                      "WWLLLWW",
                      "WLLLLWW"};
//    paint(m,0,1);
    m={"LLLLLLLLLLLLLLLLLLLL",
       "LLLLLLLLLLLLLLLLLLLL",
       "LLLLLLLLLLLLLLWLLLLL",
       "LLWWLLLLLLLLLLLLLLLL",
       "LLWWLLLLLLLLLLLLLLLL",
       "LLLLLLLLLLLLLLLLLLLL",
       "LLLLLLLWWLLLLLLLLLLL",
       "LLLLLLLLWWLLLLLLLLLL",
       "LLLLLLLLLWWWLLLLLLLL",
       "LLLLLLLLLLWWWWWWLLLL",
       "LLLLLLLLLLWWWWWWLLLL",
       "LLLLLLLLLLWWWWWWLLLL",
       "LLLLWWLLLLWWWWWWLLLL",
       "LLLLWWWLLLWWWWWWWWWW",
       "LLLLLWWWWWWWWWWWLLLL",
       "LLLLLLLLLLLLLLWWWWLL",
       "LLLLLLLLLLLLLLWLLLLL",
       "LLLLWLLLLLLLLLLLLWLL",
       "LLLLLLLLLLLLLLLLLLWL"};
    paint(m,9,12);
    assert(m[9][11]=='O');
    cout<<"YES"<<endl;
    return 0;
}

