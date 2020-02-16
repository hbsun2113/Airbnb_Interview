#include<bits/stdc++.h>
using namespace std;

//https://github.com/jxr041100/system_design/blob/master/Airbnb:%20Decode%20string
int decode(string &s){
    string correct="kljJJ324hijkS_";
    if(s==correct) return 848662;
    else return -1;
}

int seek(string s, int index){
    if(index==s.size()) return decode(s);
    if(!isalpha(s[index])) return seek(s,index+1);
    int t1=seek(s,index+1);
    if(t1!=-1) return t1;
    string tmp=s;
    tmp[index]^=32;
    return seek(tmp,index+1);
}

int main(){
    cout<< seek("kLjjj324hijks_",0)<<endl;
    cout<< seek("kLjjj324hijKs_",0)<<endl;

    cout<< seek("Ljjj324hijks_",0)<<endl;
    cout<< seek("WLjjj324hijks_",0)<<endl;
    cout<< seek("kLjjj334hijks_",0)<<endl;
    cout<< seek("kLjjj324hijks",0)<<endl;

}