#include"bits/stdc++.h"
using namespace std;
class Solution {
public:
    // 三刷照样没有bug free
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i=0;
        while(i<words.size()){
            int len=0;
            int j=i;
            while(j<words.size() && len+(j-i)+words[j].size()<=maxWidth){ // 易错：有等于号，因为是预分配
                len+=words[j].size();
                j++;
            } 
            cout<<i<<" "<<j<<endl;
            
            int space=1;
            int extra=0;
            if(j!=words.size() && j!=i+1){
                space=((maxWidth-len)/(j-i-1)); // 易错：是(maxWidth-len)
                extra=((maxWidth-len)%(j-i-1));
            }
            
            string line="";
            for(int k=i;k<j;k++){
                line+=words[k];
                if(k!=j-1) line+=string(space,' ');  // 易错：这里是有两个if的
                if(extra-->0) line+=" ";
            }
            if(line.size()<maxWidth) line+=string(maxWidth-line.size(),' ');
            res.push_back(line);
            
            i=j;
        }
        return res;
    }
    
    
    // https://www.cnblogs.com/grandyang/p/4350381.html 的思想
    // https://leetcode.com/problems/text-justification/discuss/24873/Share-my-concise-c++-solution-less-than-20-lines 中 @rpfly3的代码
    // 二刷没有bugfree
    vector<string> fullJustify2(vector<string>& words, int w) {
        vector<string> ans;
        int i=0;
        while(i<words.size()){
            int cur=0;
            int j=i;
            while(j<words.size() && cur+words[j].size()+(j-i)<=w) cur+=words[j++].size();
            // cout<<i<<" "<<j<<endl;
                
             // 这是为了最后一行准备的默认值
            int space=1;
            int extra=0;
            
            if(j!=words.size() && j-1!=i){
                space=(w-cur)/(j-i-1); // j-i-1 是空的数目，space是空的大小
                extra=(w-cur)%(j-i-1);
            }
            
            string line="";
            for(int k=i;k<j;k++){
                line+=words[k];
                if(k!=j-1) line+=string(space,' ');  // 注意前后顺序前往别搞混，数量在前，并且第二个参数是char,不是string！！
                if(extra-->0) line+=" ";
            }
            line+=string(w-line.size(),' '); // 这是为最后一行准备的
            ans.push_back(line);
            
            i=j;
        }

        return ans;
    }
};