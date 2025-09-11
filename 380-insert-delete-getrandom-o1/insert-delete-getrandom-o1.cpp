class RandomizedSet {
public:

    vector<int>arr;
    int i = 0;
    unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            arr.push_back(val);
            mp[val] = i++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()){
            int ind = mp[val];
            mp[arr[i-1]] = ind;

            swap(arr[ind], arr[i-1]);
            arr.pop_back();
            i--;
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */