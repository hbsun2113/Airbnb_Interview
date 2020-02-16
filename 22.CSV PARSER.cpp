#include<unistd.h>
#include<stack>
#include"bits/stdc++.h"
using namespace std;
//https://www.1point3acres.com/bbs/thread-218100-1-1.html
/*
0. 逗号后面紧接着的字符如果不是引号，那么到下一个逗号之前，所有的字符均原样打印（所以严格来说你举的两个例子其实没有意义，因为你在逗号后面都加了空格，Excel会对所有的引号原样输出。所以CSV中一般是不在逗号后面加空格的）。
1. 如果逗号后面出现了一个引号A，那么现在立即进入“引号模式”。A引号不打印。
2. 进入该模式后，引号必须是成对出现的。此时的每一对引号打印出来是一个引号。除此以外均原样打印
3. 在引号模式中如果竟然遇到了一个单独出现的引号B，那么就立即退出“引号模式”。B引号不打印。
4. 退出引号模式后到下一次遇到逗号之前，不会再次进入引号模式。所有出现的引号和其他字符全部原样打印。
 */
// http://cdn.hbsun.top/FgCLiNriODnVwUzE_Mk5c-G0Ckg1
vector<string> parseCSV(string s) {
    vector<string> ans;
    bool inQuote = false;  // 标志是否已经被括号包围了
    string tmp = "";
    for (int i = 0; i < s.length(); ++i) {
        if (inQuote) {
            if (s[i] == '"') {  //"
                if (i == s.length() - 1) {
                    ans.push_back(tmp);
                    return ans;
                } else if (s[i + 1] == '"') {
                    tmp += '"';
                    ++i; // 别忘了
                } else {
                    cout<<"i="<<i<<endl; // "Alexandra ""Alex"""s,Menendez,alex.menendez@gmail.com,Miami,1
                    ans.push_back(tmp);
                    tmp = "";
                    inQuote = false;
                    i++; // 别忘了
                }
            }
            else {
                tmp += s[i];
            }

        }
        else {
            if (s[i] == '"')
                inQuote = true;
            else if (s[i] == ',') {
                ans.push_back(tmp);
                tmp = "";
            } else tmp += s[i];
        }
    }
    if (!tmp.empty()) ans.push_back(tmp);
    return ans;
}

int main() {
    string ss[] = {"John,Smith,john.smith@gmail.com,Los Angeles,1",
                   "\"Alexandra \"\"Alex\"\"\",Menendez,alex.menendez@gmail.com,Miami,1"};
    for (auto s : ss) {
        cout << s << endl;
        auto parsed = parseCSV(s);
        for (int i = 0; i < parsed.size() - 1; ++i)
            cout << parsed[i] << "|";
        cout << parsed[parsed.size() - 1] << endl;
        cout << "----------------------" << endl;
    }
    return 0;
}