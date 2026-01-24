class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0) return false;
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mpp;
        for(auto &it : nums){
            mpp[it]++;
        }
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            
            if(mpp.count(nums[i])){
                int num = nums[i];
                if(mpp.count(num) == 0) continue;
                mpp[num]--;
                if(mpp[num] == 0) mpp.erase(num);
                for(int j = 0 ; j < k-1 ; j++){
                    if(mpp.count(num+1) == 0){
                        return false;
                    }else{
                        mpp[num+1]--;
                        if(mpp[num+1] == 0) mpp.erase(num+1);
                        num = num+1;
                    }
                }
            }
        }

        return true;
    }
};