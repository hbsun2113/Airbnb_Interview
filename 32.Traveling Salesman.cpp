#include<unistd.h>
#include<stack>
#include"bits/stdc++.h"

#define dbv(v) cout << #v << "="; for (auto _x : v) cout << _x << ", "; cout << endl
using namespace std;

class Solution {
public:
    /**
     * @param n: an integer,denote the number of cities
     * @param roads: a list of three-tuples,denote the road between cities
     * @return: return the minimum cost to travel all cities
     */
//    https://www.bilibili.com/video/av36363110/
//    https://www.lintcode.com/problem/traveling-salesman/my-submissions?_from=ladder&&fromId=109
//    典型的TSP问题    
    int minCost(int n, vector<vector<int>> &roads) {
        if (roads.size() == 0) return 0;
        vector<vector<int>> graph(n, vector<int>(n, -1));
        for(int i=0;i<n;i++) graph[i][i]=0;
        for (const auto &v:roads){

            // lintcode上测试用例有错误，所以用这一行来跳过错误的测试用例
            if(graph[v[0] - 1][v[1] - 1]!=-1 && graph[v[0] - 1][v[1] - 1]<v[2]) continue;

            graph[v[0] - 1][v[1] - 1] = v[2];  // 将从1开始转换为从0开始
            graph[v[1] - 1][v[0] - 1] = v[2];
        }

        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX)); // dp[i][j]代表遍历了i中所有节点，并且以j为末尾时，最小的cost
        vector<vector<int>> parent(1 << n, vector<int>(n));

        dp[1<<0][0]=0; // 因为题意规定只能从起点0开始

        for (int i = 1; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if (!(i & (1 << j))) continue;
                int prev = i - (1 << j);
                for (int k = 0; k < n; k++) {
                    if (dp[prev][k] == INT_MAX) continue;
                    if(graph[k][j]==-1) continue;  // 如果两个点之间没有连线
                    if (dp[prev][k] + graph[k][j] >= dp[i][j]) continue;
                    dp[i][j] = dp[prev][k] + graph[k][j];
                    parent[i][j] = k;
                }
            }
        }

        // 调试之用，用来打印路径
        /*
        auto it = min_element(dp.back().begin(), dp.back().end());
        int cur = it - dp.back().begin();
        cout << cur << endl;
        int s = (1 << n) - 1;
        while (s) {
            cout << cur << " "<<dp[s][cur]<<endl;
            int prev = parent[s][cur];

            s &= ~(1 << cur);
            cur = prev;
        }
        cout << "---------------" << endl;
        */

        int res = INT_MAX;
        for (const auto &t:dp.back()) res = min(res, t);

        return res;
    }
};

int main() {
    vector<vector<int>> roads = {{1,2,9},{2,3,1},{3,4,9},{4,5,4},{2,4,3},{1,3,2},{5,4,9}};
    int n = 5;
    Solution s;
    cout << s.minCost(n, roads) << endl;
    return 0;
}