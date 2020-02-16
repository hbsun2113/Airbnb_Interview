#include<unistd.h>
#include<stack>
#include"bits/stdc++.h"

using namespace std;

//https://github.com/allaboutjst/airbnb/blob/master/src/main/java/collatz_conjecture/CollatzConjecture.java
// 如此简单的题竟然调试了
class Solution {
public:
    unordered_map<int, int> um; // memorysize
    int help(int n) {
        if (um.find(n) != um.end()) return um[n];
        int res;
        if (n <= 1) res = 1;
        else if (n % 2 == 1) res = help(3 * n + 1) + 1;
        else res = help(n / 2) + 1;
        um[n] = res;
        return res;
    }

    // 题目要求：Given an integer n, output the max steps of transform number in [1, n] into 1.
    int findSteps(int n) {
//    help(n); // 注意单纯调用help(n)，不代表求得了[1,n]中所有的数字
        int maxv = 1;
        for (int i = 1; i <= n; i++) {
            maxv = max(maxv, help(i));
        }
        return maxv;
    }
};

int main() {
    Solution sol;
    assert(1 == sol.findSteps(1));
    assert(20 == sol.findSteps(10));
    assert(112 == sol.findSteps(37));
    assert(119 == sol.findSteps(101));
    return 0;
}