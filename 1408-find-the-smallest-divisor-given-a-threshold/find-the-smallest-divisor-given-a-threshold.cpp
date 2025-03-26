class Solution {
public:
    bool helper(vector<int>&a,int limit,int mid){
        int  n = a.size();
        int total = 0;
        for(int i = 0; i < n ; i++){
            total += ceil((double)a[i]/(double)mid);
        }

        if(total <= limit) return true;
        return false;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = 1;
        while(low <= high){
            int mid = (low+high)/2;
            if(helper(nums,threshold,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low= mid+1;
            }
        }
        return ans;
    }
};