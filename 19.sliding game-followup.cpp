#include<bits/stdc++.h>

using namespace std;
// 如果要拓展为m*n个格子，那么我们就要显示地构造target和change，其他的没有改变

class Solution {
public:
    int row,col,len;
    vector<vector<int>> change;



    void buildchange(){
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};
        vector<vector<int>> m(row,vector<int>(col,0));
        int k=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                m[i][j]=k++;
            }
        }
        change.resize(len);

        int c=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                for(int k=0;k<4;k++){
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(x<0 || x>=row || y<0 || y>=col) continue;
                    change[c].push_back(m[x][y]);
                }
                c++;
            }
        }

        for(const auto &v:change){
            for(const auto &n:v){
                cout<<n<<" ";
            }
            cout<<endl;
        }
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        row=board.size();
        col=board[0].size();
        len=row*col;
        string target="";
        for(int i=1;i<len;i++) target+=to_string(i);
        target+=to_string(0);
        cout<<target<<endl;

        buildchange();

        unordered_set<string> vis;
        string cur="";
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                cur+=to_string(board[i][j]);
            }
        }
        if(cur==target) return 0;

        vis.insert(cur);
        queue<string> q;
        q.push(cur);
        int res=0;
        while(!q.empty()){
            for(int i=q.size()-1;i>=0;i--){
                auto t=q.front();
                // cout<<t<<endl;
                if(t==target) return res;
                q.pop();
                int pos=seek(t);
                for(const int j:change[pos]){
                    string w=t;
                    swap(w[pos],w[j]);
                    if(vis.find(w)!=vis.end()) continue;
                    vis.insert(w);
                    q.push(w);
                }
            }
            res++;
        }
        return -1;
    }

    int seek(string &s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') return i;
        }
        return -1;
    }


};

int main() {
    Solution s;
    vector<vector<int>> board={{1,2,3},{4,0,5}};
    cout<<s.slidingPuzzle(board)<<endl;
    return 0;
}
