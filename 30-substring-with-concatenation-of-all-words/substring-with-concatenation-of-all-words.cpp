class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>mpp,freq;
        for(auto &it : words){
            mpp[it]++;
        }

        
        int len = words[0].size();
        vector<int>res;
        for(int k = 0 ; k < len ; k++){
            int i = k,j=k;

            while(j < s.size()){
                string str = s.substr(j,len);

                if(!mpp.count(str)){
                    j+=len;
                    i=j;
                    freq.clear();
                    continue;
                }
                freq[str]++;
                while(freq[str] > mpp[str]){
                    string w = s.substr(i,len);
                    freq[w]--;
                    i+=len;
                }

                if(freq==mpp){
                    res.push_back(i);
                }

                j+=len;
            }
            freq.clear();
        }
        return res;
    }
};