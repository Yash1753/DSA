class Solution {
public:
    int MOD = (int)1e9 + 7;

    vector<long long> preSAMI(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<long long> ans(n);

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<long long> postSAMI(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<long long> ans(n);

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<long long> preSAM(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<long long> ans(n);

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<long long> postSAM(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<long long> ans(n);

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    long long SAM(vector<int>& nums) {
        auto pre = preSAM(nums);
        auto next = postSAM(nums);
        long long total = 0;

        for(int i = 0; i < nums.size(); i++) {
            long long left = i - pre[i];
            long long right = next[i] - i;
            total = (total + nums[i] * left * right);
        }
        return total;
    }

    long long SAMI(vector<int>& nums) {
        auto pre = preSAMI(nums);
        auto next = postSAMI(nums);
        long long total = 0;

        for(int i = 0; i < nums.size(); i++) {
            long long left = i - pre[i];
            long long right = next[i] - i;
            total = (total + nums[i] * left * right);
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return SAM(nums) - SAMI(nums);
    }
};
