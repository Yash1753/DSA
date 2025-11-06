class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        unordered_map<char,int>mpp;

        int l=0,r=0;
        int minStart = 0;

        for(auto &ch : t){
            mpp[ch]++;
        }
        int required =t.length();
        int window = INT_MAX;
        while(r < n){
            auto ch = s[r];
            if(mpp[ch] > 0) required--;

            mpp[ch]--;

            while(required == 0){
                int minWindow = r-l+1;

                if(window > minWindow){
                    window = minWindow;
                    minStart = l;
                }

                mpp[s[l]]++;

                if(mpp[s[l]] > 0) required++;

                l++;

            }
            r++;
        }

        return window == INT_MAX ? "" : s.substr(minStart, window);
    }
};