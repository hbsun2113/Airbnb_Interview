#include<unistd.h>
#include"bits/stdc++.h"
using namespace std;


// https://yezizp2012.github.io/2017/06/01/airbnb%E9%9D%A2%E8%AF%95%E9%A2%98%E6%B1%87%E6%80%BB/
// https://www.1point3acres.com/bbs/interview/airbnb-software-engineer-231042.html
// 这道题目似乎只能使用iterator做，因为要删除当前元素并且不影响后面的元素。注意erase当前元素后，自动就指向了下一个元素。
// 其实是指针的指向没有改变，是后面的元素自动向前移动了。
/* 证明代码：
#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<int> vec={1,2,3,4,5,6,7,8,9};
  auto it=vec.begin();
  while(!vec.empty()){
    auto _ptr = &(*it);
    cout<<*it<<" "<<_ptr<<endl;
    vec.erase(it);
  }
  return 0;
}
*/
vector<vector<string> > paging(vector<string> items, int size) {
    vector<vector<string> > ans;
    const int n = items.size();
    for (int i = 0; i <= (n - 1) / size; ++i) {
        vector<string> tmp;
        unordered_set<string> st;
        for (auto it = items.begin(); it != items.end() && tmp.size() < size;) {
            if (st.count(*it)) {
                ++it;
                continue;
            }
            st.insert(*it);
            tmp.push_back(*it);
            items.erase(it);
        }
        for (auto it = items.begin(); it != items.end() && tmp.size() < size;) {
            tmp.push_back(*it);
            items.erase(it);
        }
        ans.push_back(tmp);
    }
    return ans;
}

vector<vector<string>> mypaging(vector<string> items, int size) {
    vector<vector<string>> res;
    int n = items.size();
    for (int i = 0; i < (n + size - 1) / size; i++) {
        unordered_set<string> us;
        vector<string> tmp;
        for (auto it = items.begin(); it != items.end() && tmp.size() < size;) {
            auto t = *it;
            if (us.find(t) != us.end()) {
                it++;
                continue;
            }
            us.insert(t);
            tmp.push_back(t);
            items.erase(it); // eraseºóÖ¸ÏòÏÂÒ»¸öÔªËØ
        }

        for (auto it = items.begin(); it != items.end() && tmp.size() < size;) {
            auto t = *it;
            tmp.push_back(t);
            items.erase(it);
        }

        res.push_back(tmp);
    }
    return res;
}

// 再刷
vector<vector<string> > paging2(vector<string> items, int size) {
    vector<vector<string>> res;
    auto it = items.begin();
    int n = items.size();
    int len = (n + size - 1) / size;
    for (int i = 0; i < len; i++) {
        vector<string> tmp;
        unordered_set<string> vis;
        auto it = items.begin();
        while (it != items.end() && (int) tmp.size() < size) {
            if (vis.find(*it) != vis.end()) {
                it++;
                continue;
            }
            vis.insert(*it);
            tmp.push_back(*it);
            items.erase(it);
        }

        it = items.begin();
        while (it != items.end() && (int)tmp.size() < size) {
            tmp.push_back(*it);
            items.erase(it);
        }

        res.push_back(tmp);
    }
    return res;
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 1, 5, 1, 2, 3, 1, 3};
    vector<string> items;
    for (auto &n:vec) items.push_back(to_string(n));
    auto res = paging(items, 5);
    for (auto &v:res) {
        for (auto &n:v) {
            cout << n << " ";
        }
        cout << endl;
    }
}



