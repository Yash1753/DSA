class Solution {
public:

    bool fn(int mid,vector<int>& weights, int days){
        long long sum = 0;
        int d = 1;

        for(auto it : weights){
            if(sum + it > mid){
                d += 1;
                sum = 0;
            }
            sum += it;
        }

        return d <=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        //withdin days m jayegi shipment
        //can not load more than max capaictu 
        //least weight capacity btao within days
        int n = size(weights);
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(fn(mid,weights,days)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};