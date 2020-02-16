#include<bits/stdc++.h>

using namespace std;
// 相比于lc,多了一个通配符
//https://github.com/allaboutjst/airbnb/blob/master/src/main/java/regular_expression/RegularExpression.java
bool match(string &&s, string &&p){
    int lens=s.size();
    int lenp=p.size();
    vector<vector<bool>> dp(lens+1,vector<bool>(lenp+1,false));
    dp[0][0]=true;
    for(int i=1;i<=lenp;i++){
        if(p[i-1]=='*'){
            dp[0][i]=dp[0][i-1];
            if(i-2>=0) dp[0][i]=dp[0][i-2];
        }
        else if(p[i-1]=='+')
            dp[0][i]=dp[0][i-1];
    }

    for(int i=1;i<=lens;i++){
        for(int j=1;j<=lenp;j++){
            if(s[i-1]==p[j-1] || p[j-1]=='.')
                dp[i][j]=dp[i-1][j-1];
            else if(p[j-1]=='*'){
                if(j-2>=0 && (p[j-2]==s[i-1] || p[j-2]=='.') )
                    dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2];
                else if(j-2>=0)
                    dp[i][j]=dp[i][j-2];
            }
            else if(p[j-1]=='+'){
                if(j-2>=0 && (p[j-2]==s[i-1] || p[j-2]=='.') )
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
    }

    return dp.back().back();
}

int main() {
    assert(match("saaaa", "s+a*"));
    assert(!match("saaaa", "s+b*"));
    assert(!match("saaaab", "s+a*"));
    assert(!match("saaaab", "s+b*"));
    cout<<"True"<<endl;
    return 0;
}