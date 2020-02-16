#include<unistd.h>
#include<stack>
#include"bits/stdc++.h"
using namespace std;

// 感觉和它的思想是一样的：https://wuzequn.com/2019/03/18/interview-coding-airbnb/#more
// 记住32
// 在[l,r]区间中找到小于等于自己的个数等于cnt的数字n
int find(vector<int> &vec, int cnt, long long l, long long r) {
    while (l < r) {
        int tmp = 0;
        long long mid = r + l >> 1;
        for (const auto &n:vec) {
            if (n <= mid) tmp++;
        }
        if (tmp >= cnt) r = mid;  //[l,mid] [mid+1,r]
        else l = mid + 1;
    }
    return l;
}

int main() {
    long long len=0ll + INT_MAX + llabs(INT_MIN);
    cout<<len<<" "<<log2(len)<<endl;

//    vector<int> vec={1,2,3,4,5,6,7}; // 奇数
    vector<int> vec = {-12, -10, -3, -1, 2, 4, 5, 6, 7, 9}; // 偶数
//    vector<int> vec={2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
//    vector<int> vec={2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};
    int n = vec.size();
    double res;
    int t1 = find(vec, (n + 1) / 2, INT_MIN, INT_MAX);
    int t2 = find(vec, (n + 2) / 2, INT_MIN, INT_MAX);
    cout << t1 << " " << t2 << endl;
    res = (double(t1) + t2) / 2.000;
    cout << res << endl;

    return 0;
}