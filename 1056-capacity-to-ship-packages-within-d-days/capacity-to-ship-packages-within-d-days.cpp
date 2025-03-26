class Solution {
public:
    bool helper(vector<int>&a,int days ,int mid){
        int n  = a.size();
        int d = 1,load = 0;
        for(int i =0 ; i<n ; i++){
            load += a[i];
            if (load > mid) {
            d+= 1; //move to next day
            load = a[i]; //load the weight.
        }
       
            //load the weight on the same day.
            
        
        }

        
        if(d<= days)return true;
        return false;   

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int high = accumulate(weights.begin(), weights.end(), 0);
        int low = *max_element(weights.begin(), weights.end());
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(helper(weights,days,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
}; 