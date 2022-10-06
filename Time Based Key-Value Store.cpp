class TimeMap {
public:
    unordered_map<string, set<pair<int,string>>> mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp, value}); 
    }
    
    string get(string key, int timestamp) {
        if(mp[key].size() != 0){
            auto it = mp[key].upper_bound({timestamp, "~"});
            if(it == mp[key].begin()) return "";
            --it;
            return it->second;
        }
        return "";
    }
};
