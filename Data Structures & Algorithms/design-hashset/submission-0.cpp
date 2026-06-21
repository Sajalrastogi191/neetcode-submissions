class MyHashSet {
public:
    unordered_map<int,int> um;
    MyHashSet() {
        
    }
    
    void add(int key) {
        um[key]++;
    }
    
    void remove(int key) {
        um.erase(key);
    }
    
    bool contains(int key) {
        return um.find(key) != um.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */