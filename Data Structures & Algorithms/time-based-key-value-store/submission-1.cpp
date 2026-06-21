class TimeMap {
public:
    unordered_map<string,map<int,string>> um;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        um[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = um.find(key);

        if (it == um.end()) return "";

        auto &mp = it->second;

        auto pos = mp.upper_bound(timestamp);

        if (pos == mp.begin()) return "";

        pos--;
        return pos->second;
    }
};
