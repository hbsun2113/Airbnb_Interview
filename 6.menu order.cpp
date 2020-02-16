#include"bits/stdc++.h"
using namespace std;
class Solution {
public:
    // 再刷做得不好：https://leetcode.com/submissions/detail/250747184/
    
    //忘记几刷了，自己AC的。
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int sum=0;
        helper(candidates,target,0,0);
        return res;
    }
    
    void helper(vector<int>& candidates, int target, int sum, int index){
        if(sum>target || index>candidates.size()) return;
        if(sum==target){
            res.push_back(tmp);
            return ;
        }
        for(int i=index;i<candidates.size();i++){
            if(i!=index && candidates[i]==candidates[i-1]) continue;  //这条规则可以记一下。头部节点不使用重复值，也就是当前层不使用重复值。
            tmp.push_back(candidates[i]);
            sum+=candidates[i];
            helper(candidates,target,sum, i+1);
            sum-=candidates[i];
            tmp.pop_back();
        }
    }
    
    
    // https://leetcode.com/problems/combination-sum-ii/discuss/16861/Java-solution-using-dfs-easy-understandcuyuan 说得比较好:
    /*
    For those who don't understand how to avoid duplicate by:
if "(i > cur && cand[i] == cand[i-1]) continue;

when we should skip a number? not just it's the same as previous number, but also when it's previous number haven't been added!

i > cur means cand[i - 1] is not added to the path (you should know why if you understand the algorithm), so if cand[i] == cand[i-1], then we shouldn't add cand[i].

This tricky is very smart.
    */
    // 注意for循环的意思是我们在本层递归中，我们只取一个元素，然后进入下一层
};