#include<unistd.h>
#include<stack>
#include"bits/stdc++.h"
using namespace std;
// https://leetcode.com/problems/multiply-strings/description/
// 可以处理负数
string multiply(string num1, string num2) {
    int m=num1.size(),n=num2.size(); //num1的低位存数字的高位。最低位也可能存储的是
    int i=0;
    int j=0;
    int flag=1;
    if(num1[0]=='-'){
        flag*=-1;
        i++;
    }
    if(num2[0]=='-'){
        flag*=-1;
        j++;
    }

    vector<int> a(m),b(n),c(m+n);  // a的低位存数字的低位 // c的低位存数字的低位
    for(;i<m;i++) a[m-i-1]=(num1[i]-'0'); // 先把string的逆序转换成正常顺序，然后我们就可以进行正常的计算了
    for(;j<n;j++) b[n-j-1]=(num2[j]-'0');

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            c[i+j]+=(a[i]*b[j]);
            c[i+j+1]+=(c[i+j])/10;  // 易错
            c[i+j]%=10;
        }
    }

    i=m+n-1;
    while(i>0 && c[i]==0) i--; // 注意没有等于号
    string res="";
    while(i>=0) res+=to_string(c[i--]);
    if(flag==-1) res="-"+res;
    return res;
}


int main() {
    long long num1=-1235;
    long long num2=-2333;
    long long target=num1*num2;
    string res=multiply(to_string(num1),to_string(num2));
    cout<<(stoll(res)==target)<<endl;
    cout<<res<<" "<<target<<endl;
    return 0;
}