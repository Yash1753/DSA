class Solution {
public:
    bool isValid(vector<int>&a, int days ,int mid){
        int n  = a.size();
        int d = 1,load = 0;
        for(int i =0 ; i<n ; i++){
            if (load + a[i] > mid) {
            d+= 1; //move to next day
            load = a[i]; //load the weight.
        }
        else {
            //load the weight on the same day.
            load += a[i];
        }
        }

        
        if(d<= days)return true;
        return false;   
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = size(weights);
        int l = *max_element(weights.begin(), weights.end()), r = accumulate(begin(weights),end(weights),0);
        int ans= -1;
        while(l<=r){
            int mid = l + (r-l)/2;

            if(isValid(weights,days,mid)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};