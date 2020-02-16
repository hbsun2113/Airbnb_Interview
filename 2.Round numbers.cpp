#include "bits/stdc++.h"
using namespace std;
#define dbv(v) cout << #v << "="; for (auto _x : v) cout << _x << ", "; cout << endl
class Solution {
public:
    // https://leetcode.com/problems/minimize-rounding-error-to-meet-target/description/
    // 思想来源于：https://yezizp2012.github.io/2017/06/01/airbnb%E9%9D%A2%E8%AF%95%E9%A2%98%E6%B1%87%E6%80%BB/
    // Round numbers
    // 首先确定所有两个极限：全部floor和全部ceil，如果target不介于两者之间，则直接返回-1即可
    // 然后我们只利用floor了：
    // 1. 我们比较floor和target，差多少，我们就要将多少个num变为ceil
    // 2. 那选择那些num变为ceil呢？我们要选尽可能选差值最小的：ceil(num)-num越小越好，因此这是贪心策略
    // 3. 因此按照这个这个规则对vec进行排序，注意有一个边界情况：即ceil(num)==num，而且它们是排在最前面的，我们要跳过它们
    string minimizeError(vector<string>& prices, int target) {
        int _min=0,_max=0,all=0;
        vector<pair<double,int>> vec;
        vector<int> res;
        for(int i=0;i<prices.size();i++){
            auto n=prices[i];
            double p=stod(n);
            int fp=floor(p);
            all+=p;
            _min+=fp;
            _max+=ceil(p);
            vec.push_back({p,i});
            res.push_back(fp);
        }
        
        if(target>_max || target<_min) return "-1";
        
        auto cmp=[](pair<double,int>& a, pair<double,int>& b){
            return ceil(a.first)-a.first<ceil(b.first)-b.first;
        };
        
        sort(vec.begin(),vec.end(),cmp);
        
        // The only cornor case is when there is no round up error, we need to skip such element
        // https://leetcode.com/problems/minimize-rounding-error-to-meet-target/discuss/305837/C++-greedy-O(NlogN)
        // 跳过 ceil(num)==num 的这些
        int zero=0;
        while(zero<res.size() && ceil(vec[zero].first)-vec[zero].first==0) zero++;
        cout<<zero<<endl;
        for(int i=zero;i<target-_min+zero;i++){
            res[vec[i].second]++;
        }
        
        double ans=0;
        for(int i=0;i<prices.size();i++){
            ans+=abs(vec[i].first-res[vec[i].second]);
        }
        
        cout<<accumulate(res.begin(),res.end(),0.00)<<endl;
        string s=to_string(ans);
        return s.substr (0, s.find_first_of ('.', 0) + 4);
    }
};