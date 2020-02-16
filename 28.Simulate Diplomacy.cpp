#include<bits/stdc++.h>

using namespace std;
// https://www.cnblogs.com/greatLong/p/10676209.html
// 这道题目的灵魂之处是要使用指针，使得Location2Army和All共同持有同一份数据

class Army {
public:
    string name;
    string action;
    string location;
    int length = 1;
    string support_id = "";

    Army(string &s) {
        istringstream ins(s);
        getline(ins, name, ' ');
        getline(ins, location, ' ');
        getline(ins, action, ' ');
        if (action == "Hold") {
        } else if (action == "Move") {
            getline(ins, location, ' ');
        } else if (action == "Support") {
            getline(ins, support_id, ' ');
        }
    }

    string to_string() const {
//        cout << name << " " << location << " " << length << endl;
        cout << name << " " << location << endl;
    }
};


int main() {
    vector<string> vec = {"A Munich Hold", "B Bohemia Move Munich", "C Warsaw Support B"};
    vec = {"A Munich Hold", "B Warsaw Move Bohemia"};
    vec = {"A Munich Hold","B Bohemia Move Munich","C Warsaw Support B"};
    vec = {"A Munich Hold", "B Bohemia Move Munich", "C Prussia Move Munich", "D Warsaw Hold"};
    vec = {"A Munich Support B", "B Bohemia Move Prussia", "C Prussia Hold", "D Warsaw Move Munich"};
    vec = {"A Munich Support B", "B Oakland Move Munich"};
    map<string, Army *> All;
    unordered_map<string, vector<Army *>> Location2Army;
    for (auto &s:vec) {
        Army *ptr_Army = new Army(s);
        All.insert(std::make_pair(ptr_Army->name, ptr_Army));
        Location2Army[ptr_Army->location].push_back(ptr_Army);
    }

    // 统计每个队伍是否可以support其他队伍
    for (auto &n:Location2Army) {
        // cout<<n.first<<" "<<n.second.size()<<endl;
        if (n.second.size() <= 1) {
            string &support = n.second[0]->support_id;
            if (All.find(support) != All.end()) {
                All[support]->length += 1;
            }

        }
    }

    // 决定每个地点是哪个队伍占领了
    auto cmp = [](Army *a, Army *b) {
        return a->length < b->length;
    };
    for (auto &n:Location2Army) {
        if (n.second.size() <= 1) continue;
        sort(n.second.begin(), n.second.end(), cmp);
        int maxv = n.second.back()->length;
//        cout<<n.second.back()->name<<" "<<n.second.back()->length<<endl;
//        cout<<n.first<<" "<<n.second.size()<<" "<<maxv<<endl;
        int cnt = 0;
        for (const auto &t:n.second) {
            cnt += (t->length == maxv);
        }
        for (auto &t:n.second) {
            t->location = "[dead]";
        }
        if (cnt == 1)
            n.second.back()->location = n.first;
    }

    for (const auto &n:All) {
        n.second->to_string();
        delete (n.second);
    }

    return 0;
}