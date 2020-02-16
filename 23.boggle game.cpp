#include<unistd.h>
#include<stack>
#include"bits/stdc++.h"
#define dbv(v) cout << #v << "="; for (auto _x : v) cout << _x << ", "; cout << endl
using namespace std;
// https://www.jiuzhang.com/solution/boggle-game/#tag-other-lang-cpp
// https://www.lintcode.com/problem/boggle-game/description?_from=ladder&&fromId=109
// 暴力求解，即遍历每一个点，以它为起点看看是否可以组成一个单词。
// 如果可以就cnt++,然后遍历矩阵所有还未利用的点，作为起点。
// 如果还没有组成一个完整的单词，就向四周探索即可。
// 这道题目的独特点就在于根据不同状态进行不同的dfs。
class Node {
public:
    unordered_map<char, Node*> um;
    bool isword = false;
};

class Solution {
public:
    Node *root = new Node();
    void build(vector<string> dict) {
        for (const auto &s:dict) {
            auto cur = root;
            for (const auto &c:s) {
                if (cur->um.find(c) == cur->um.end()) cur->um[c] = new Node();
                cur = cur->um[c];
            }
            cur->isword = true;
        }
    }

    int res = INT_MIN;
    int row, col;
    int boggleGame(vector<vector<char>> &board, vector<string> &words) {
        build(words);
        row = board.size();
        col = board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                auto cur=root;
                char c=board[i][j];
                if(cur->um.find(c)==cur->um.end()) continue;
                board[i][j]='X';
                string tmp="";
                dfs(i,j,cur->um[c],0,i,j,tmp+c,board);
                board[i][j]=c;
            }
        }
        return res;
    }

    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    void dfs(int x, int y, Node *cur, int cnt, int startx, int starty, string tmp, vector<vector<char>> &board) {
//        cout<<x<<" "<<y<<" "<<cur->isword<<" "<<board[x][y]<<endl;
        board[x][y]='X';
        if(cur->isword){
            cnt++;
            res=max(cnt,res);
            cur=root; // 重新开始了
            tmp="";
            for(int i=startx;i<row;i++){
                for(int j=starty;j<col;j++){
                    if(board[i][j]=='X') continue;
                    char c=board[i][j];
                    if(cur->um.find(c)==cur->um.end()) continue;
                    board[i][j]='X';
                    dfs(i,j,cur->um[c],cnt,i,j,tmp+c,board);
                    board[i][j]=c;
                }
                // 问：想问下代码89行为什么要重置成y_start = 0?
                // 答：因为之前那个起点的之后所有的点都要当作起点走一遍，所以下一行的第一列从0开始，也是要走一遍的
                starty=0;
            }
        }
        else{
            for(int k=0;k<4;k++){
                int xx=x+dx[k];
                int yy=y+dy[k];
                if(xx<0 || xx>=row || yy<0 || yy>=col || board[xx][yy]=='X') continue;
                char c=board[xx][yy];
                if(cur->um.find(c)==cur->um.end()) continue;
                board[xx][yy]='X';
                dfs(xx,yy,cur->um[c],cnt,startx,starty,tmp+c,board);
                board[xx][yy]=c;
            }
        }
    }
};

int main() {
//  测试用例来源：https://github.com/allaboutjst/airbnb/blob/master/src/main/java/boggle_game/BoggleGame.java
    Solution s;
//    vector<vector<char>> board={
//            {'o', 'a', 't', 'h'},
//            {'e', 't', 'a', 'e'},
//            {'i', 'h', 'k', 'r'},
//            {'i', 'f', 'l', 'v'}
//    };
//    vector<string> dict={"oath","pea","eat","rain"};
//    cout<<(s.boggleGame(board,dict)==2)<<endl;
    vector<vector<char>> board={
            {'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a'},
            {'a', 'a', 'a', 'a'}
    };
//    board={
//            {'a', 'a', 'a', 'a'},
//    };
    vector<string> dict={"a"};
    cout<<(s.boggleGame(board,dict))<<endl;


//  测试用例来源：https://huangwenjimmy.github.io/2016/11/17/airbnb-boggle-game.html
//  vector<vector<char>> board={{'a', 'b', 'c'},
//                              {'d', 'e', 'f'},
//                              {'g', 'h', 'i'}};
//
//  vector<string> dict={"abc", "cfi", "beh", "defi", "gh"};
//  Solution s;
//  cout<<(s.boggleGame(board,dict)==3)<<endl;
}