class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 1;
        int n = nums.size();
        if(n==0) return 0; 
        unordered_set<int> st;

        for(auto it : nums){
            st.insert(it);
        }

        for(auto it : st){
            if(st.find(it-1) == st.end()){
                int cnt = 1;
                int x = it;
                x = x+1;
                while(st.find(x) != st.end()){
                    cnt++;
                    x = x+1;
                }

                longest = max(cnt,longest);

            }
        }

        return longest;
    }
};