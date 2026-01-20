class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        deque<int>dq;

        for(int i = 0 ; i < k ; i++){
            int el = nums[i];
            while(!dq.empty()&& nums[dq.back()] < el   ) dq.pop_back();
            dq.push_back(i);
        }

        for(int i = k ;i < nums.size();i++){
            res.push_back(nums[dq.front()]);
            if(!dq.empty() && i - dq.front() >= k){
                dq.pop_front();
            }
            while(!dq.empty()&& nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);

        }
        res.push_back(nums[dq.front()]);

        return res;
    }
};