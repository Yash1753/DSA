class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        //unique is <= maxL toh mpp size
        //size should be between minSize an d maxSize

        //ek map final k liye lena pdega
        unordered_map<char,int>freq;
        unordered_map<string,int>res;
        int n = s.size();
        int i = 0;
        int j = 0;

        while( j < s.size()){
            freq[s[j]]++;

            while(freq.size() > maxLetters || j-i+1 > minSize){
                freq[s[i]]--;
                if(freq[s[i]] == 0){
                    freq.erase(s[i]);
                }
                i++;
            }

            if(j-i+1 >= minSize && freq.size() <= maxLetters){
                string str = s.substr(i,j-i+1);
                res[str]++;
            }
            j++;
        }

        int ans = 0;
        for(auto &it : res){
            ans = max(ans,it.second);
        }

        return ans;
    }
};