#include"bits/stdc++.h"

using namespace std;

class Solution {
public:
    // 二刷，自己做出来了
    // dp[i][j]代表在把前i个字符转换为前j个字符需要的最小数目
    // dp[i][j]可以由dp[i-1][j-1]转化:replace或本来就相等
    // dp[i][j]可以由dp[i-1][j]转化:删除(本来i-1和j相等，那么i就是多余的，要删除)
    // dp[i][j]可以由dp[i-1][j-1]转化:插入(本来i和j-1是相等的，此时word1中无对应字符和j相等，那么就插入一个)
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 0; i <= len1; i++) dp[i][0] = i;
        for (int i = 0; i <= len2; i++) dp[0][i] = i;
        for (int i = 1; i < len1 + 1; i++) {
            for (int j = 1; j < len2 + 1; j++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]));
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
        return dp[len1][len2];
    }

    //https://leetcode.com/problems/edit-distance/discuss/25846/C++-O(n)-space-DP
    int minDistance1(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        dp[0][0] = 0;
        for (int i = 1; i <= len1; i++) dp[i][0] = i;
        for (int j = 1; j <= len2; j++) dp[0][j] = j;
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                dp[i][j] = dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]); //注意优先级，这里要有括号
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
        return dp[len1][len2];
    }
};