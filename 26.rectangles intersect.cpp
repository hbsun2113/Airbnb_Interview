#include<unistd.h>
#include<stack>
#include"bits/stdc++.h"

using namespace std;
//You have a plain with lots of rectangles on it, find out how many of them intersect
//https://github.com/allaboutjst/airbnb/blob/master/src/main/java/number_of_intersected_rectangles/NumberofIntersectedRectangles.java
// 首先要学会判断两个矩形是否相交https://leetcode.com/submissions/detail/241171391/
// 别忘了使用union find进行优化
// 相交具有传递性 如果A和B相交，B和C相交，则A和C相交

class Solution {
public:
    bool intersect(vector<int> &a, vector<int> &b) {
        int alx = a[0];
        int aly = a[1];
        int arx = a[2];
        int ary = a[3];

        int blx = b[0];
        int bly = b[1];
        int brx = b[2];
        int bry = b[3];

        int lx = max(alx, blx);
        int rx = min(arx, brx);
        if (lx >= rx) return false;

        int by = max(aly, bly);
        int ty = min(ary, bry);
        if (by >= ty) return false;

        return true;
    }

    int findroot(int i) {
        while (i != parent[i]) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }

    int countIntersection(vector<vector<int>> arr) {
        int n = arr.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (intersect(arr[i], arr[j])) {
                    int a = findroot(i);
                    int b = findroot(j);
                    if (a != b) parent[a] = b;
                }
            }
        }

        unordered_set<int> us;
        for (int i = 0; i < parent.size(); i++)
            us.insert(findroot(i)); // 注意这里面还需要再去找一遍findroot

        return us.size();
    }

    vector<int> parent;
};

int main() {
    Solution s;
    vector<vector<int>> array = {
            {-3, -2, 2,  1},
            {10, 8,  15, 10},
            {1,  0,  7,  4},
            {12, 9,  16, 12},
            {-2, -1, 5,  3}};
    cout << s.countIntersection(array) << endl;
    return 0;
}

