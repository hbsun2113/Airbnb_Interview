#include<unistd.h>
#include<stack>
#include"bits/stdc++.h"
using namespace std;

// https://massivealgorithms.blogspot.com/2016/11/airbnb-interview-misc.html
// 很常规的动态规划
// 就是在array里找到一个sequence，使得和最大，但是不可以选择相邻元素
class Solution {
 public:
  int findMaxDays(vector<int> array){
    int n=array.size();
    vector<int> vec(n);
    vec[0]=array[0];
    vec[1]=max(array[0],array[1]);
    for(int i=2;i<n;i++){
      vec[i]=max(vec[i-1],vec[i-2]+array[i]);
    }
    return vec.back();
  }
};

int main() {
  Solution s;
  vector<int> one = {1, 2, 3};
  vector<int> two = {5,1,2,6};
  vector<int> three = {5,1,2,6,20,2};
  cout<<(s.findMaxDays(one))<<endl;
  cout<<(s.findMaxDays(two))<<endl;
  cout<<(s.findMaxDays(three))<<endl;
  return 0;
}