class Solution {
public:

    string generate(string &word){
        vector<int>freq(26,0);
        for(int i = 0 ; i < word.size() ; i++){
            freq[word[i] - 'a']++;
        }

        string new_word = "";

        for(int i = 0 ; i < 26 ; i++){
            if(freq[i] > 0){
                string temp = string(freq[i], i + 'a');
                new_word+=temp;
            }
        }

        return new_word;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //vector<int>freq(26,0);
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>result;
        for(int i = 0 ; i < strs.size() ; i++){
            auto word = strs[i];
            auto new_word = generate(word);

            mp[new_word].push_back(word);
        }

        for(auto it : mp){
            result.push_back(it.second);
        }

        return result;
    }
};