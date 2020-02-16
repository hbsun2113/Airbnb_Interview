class BankSystem {
public:
    BankSystem() {
        // initialize your data structure here.
        
    }
    /**
     * @param id: user account id
     * @param amount: the number of bank deposits
     * @param timestamp: the data of bank transaction
     * @return: nothing
     */
    void deposite(int id, int amount, long long timestamp) {
        auto &v=um[id];
        if(v.size()==0) v.push_back({timestamp,amount});
        else{
            auto pre=v.back().second;
            v.push_back({timestamp,pre+amount});
        }
    }

    /**
     * @param id: user account id
     * @param amount : the number of bank withdraw
     * @param timestamp: the data of bank transaction
     * @return: if user account can not withdraw the number of amount,return false. else return true
     */
    bool withdraw(int id, int amount , long long timestamp) {
        auto &v=um[id];
        if(v.size()==0) return false;
        else{
            auto pre=v.back().second;
            if(pre<amount) return false;
            v.push_back({timestamp,pre-amount});
            return true;
        }
    }

    /**
     * @param id: user account id
     * @param startTime: start time
     * @param endTime: end time
     * @return: need return two numbers,the first one is start time account balance,the second is end time account balance
     */
    vector<int> check(int id, long long startTime, long long endTime) {
        auto &v=um[id];
        if(v.size()==0) return {};
        int l=0,r=v.size()-1;
        while(l<r){  // 找到最后一个小于等于startTime的位置
            int mid=l+r+1>>1;
            if(v[mid].first<=startTime) l=mid;  //[l,mid-1] [mid,r]
            else r=mid-1;
        }
        auto first=v[l].second;
        // cout<<id<<" "<<startTime<<" "<<endTime<<endl;
        // cout<<l<<" "<<startTime<<endl;
        if(v[l].first>startTime) first=0;
        
        l=0,r=v.size()-1;
        while(l<r){
            int mid=l+r+1>>1;
            if(v[mid].first<=endTime) l=mid;  //[l,mid-1] [mid,r]
            else r=mid-1;
        }
        auto second=v[l].second;
        if(v[l].first>endTime) second=0;
        return {first,second};
    }
    
    unordered_map<int,vector<pair<long long, int>>> um;
};