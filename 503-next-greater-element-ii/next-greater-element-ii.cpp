class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>vec = nums;
        for(auto it : nums){
            vec.push_back(it);
        }

        stack<int>st;
        int n = vec.size();
        st.push(vec[n-1]);
        vector<int>ans(n);
        ans[n-1] = -1;
        for(int i = n-2 ; i >= 0 ; i-- ){
            while(!st.empty() && st.top() <= vec[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }

            st.push(vec[i]);
        }
        vector<int>v;
        for(int i = 0  ; i < nums.size() ; i++){
            v.push_back(ans[i]);
        }

        return v;
    }
};