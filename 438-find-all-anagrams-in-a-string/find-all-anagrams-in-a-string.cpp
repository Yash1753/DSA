class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.size();
        unordered_map<char,int>orig,freq;
        for(auto &it : p){
            orig[it]++;
        }
        vector<int>ans;

        int i = 0, j = 0;
        int n = s.size();

        while(j < n){
            freq[s[j]]++;

            while(j-i+1 > k){
                freq[s[i]]--;
                if(freq[s[i]] == 0){
                    freq.erase(s[i]);
                }
                i++;
            }

            if(freq == orig){
                ans.push_back(i);
            }

            j++;
        }
        return ans;
    }
};