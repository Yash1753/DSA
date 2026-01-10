class MyHashSet {
public:
    int M;
    vector<list<int>>bucket;
    MyHashSet() {
        M = 15000;
        bucket.resize(M,list<int>{});
        
    }

    int getIndex(int key){
        return key%M;
    }
    
    void add(int key) {
        int index = getIndex(key);

        auto itr = find(bucket[index].begin() , bucket[index].end(),key);

        if(itr == bucket[index].end()){
            bucket[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index = getIndex(key);

        auto itr = find(bucket[index].begin() , bucket[index].end(),key);
         if(itr != bucket[index].end()){
            bucket[index].erase(itr);
        }

    }
    
    bool contains(int key) {
         int index = getIndex(key);

        auto itr = find(bucket[index].begin() , bucket[index].end(),key);
        return itr != bucket[index].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */