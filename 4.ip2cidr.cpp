#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 因为是ip是开始，所以只能从0变为1，不能从1变为0
    // 因为要求list尽可能小，所以每个元素要尽可能多地覆盖，又因为要连续，因为我们找到最低1，将它后面的0变为1
    vector<string> res;
    vector<string> ipToCIDR(string ip, int n) {
        long long v=0; // 注意是long long 类型
        istringstream ins(ip);
        while(getline(ins,ip,'.')){
            int num=stoi(ip);
            v*=256; // 注意是乘上256
            v+=num;
        }
        
        while(n>0){
            long long step=v&~(v-1);
            while(step>n) step/=2;
            convert(v,step);
            v+=step;
            n-=step;
        }
        
        return res;
    }
    
    void convert(int v, int step){
        string s=to_string((v>>24)&255)+"."+to_string((v>>16)&255)+"."+to_string((v>>8)&255)+"."+to_string(v&255)+"/"+to_string(32-(int)log2(step)); // 注意最后要用32去减
        res.push_back(s);
    }
};