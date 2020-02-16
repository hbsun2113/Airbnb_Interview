#include"bits/stdc++.h"
using namespace std;
//https://leetcode.com/problems/employee-free-time/description/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

class Solution {
public:
    vector<Interval*> employeeFreeTime(vector<vector<Interval*>>& schedule) {
        vector<Interval*> vec;
        for(const auto &v:schedule)
            for(const auto &c:v) 
                vec.push_back(c);
        auto cmp=[](Interval* a, Interval* b){
            if(a->start!=b->start) return a->start<b->start;
            else return a->end<b->end;
        };
        sort(vec.begin(),vec.end(),cmp);
        for(const auto &v:vec)
            cout<<v->start<<" "<<v->end<<endl;
        
        vector<Interval*> res;
        for(int i=1;i<vec.size();i++){
            int start=vec[i]->start;
            int end=vec[i-1]->end;
            if(start>end){
                res.push_back(new Interval(end,start));
            }
        }
        
        return res;
    }
};