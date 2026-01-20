class Solution {
public:
    unordered_map<string,bool>mp;
    bool isConcat(string word, unordered_set<string>&st){
        int n = word.size();
        if(mp.count(word)) return mp[word];
        for(int i = 0 ; i <n ; i++){
            string prefix = word.substr(0,i+1);
            string suffix = word.substr(i+1);

            if((st.count(prefix) && st.count(suffix)) || (st.count(prefix) && isConcat(suffix,st))) return mp[word] = true;
        }

        return mp[word] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        mp.clear();
        unordered_set<string>st(words.begin(),words.end());

        vector<string>result;
        for(int i = 0 ; i < n ; i++){
            if(isConcat(words[i],st)){
                result.push_back(words[i]);
            }
        }

        return result;
    }
};