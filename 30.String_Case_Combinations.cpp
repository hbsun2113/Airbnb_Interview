#include<bits/stdc++.h>

using namespace std;
//https://github.com/allaboutjst/airbnb/blob/master/src/main/java/find_case_combinations_of_a_string/FindCaseCombinationsofaString.java
bool permutation(string &s, vector<string> &vec) {
    transform(s.begin(), s.end(), s.begin(), ::tolower); // 先全部转化为小写
    int n = s.size();
    int base = 1 << n;
    for (int i = 0; i < base; i++) {
        string t = s;
        for (int j = 0; j < n; j++) {
            // https://www.geeksforgeeks.org/permute-string-changing-case/
            if ( ((i >> j) & 1) == 1) t[j] = toupper(t[j]);
        }
        vec.push_back(t);
    }
}

int main() {
    vector<string> vec;
    string s = "AirBnB";
    permutation(s, vec);
    assert(64 == (int) vec.size());
    assert("airbnb" == vec[0]);
    assert("Airbnb" == vec[1]);
    assert("aIRBNB" == vec[62]);
    assert("AIRBNB" == vec[63]);
    return 0;
}