#include"bits/stdc++.h"
using namespace std;
class Solution {
public:
    // https://leetcode.com/problems/ternary-expression-parser/discuss/92166/Very-easy-1-pass-Stack-Solution-in-JAVA-(NO-STRING-CONCAT)
    string parseTernary(string expression) {
        if(expression.size()==0) return expression;
        stack<char> s;
        for(int i=expression.size()-1;i>=0;i--){
            if(!s.empty() && s.top()=='?'){
                s.pop();
                auto first=s.top();
                s.pop();
                s.pop();
                auto second=s.top();
                s.pop();
                if(expression[i]=='T') s.push(first);
                else s.push(second);
            }
            else 
                s.push(expression[i]);
        }
        
        string res="";
        return res+s.top();
    }
};