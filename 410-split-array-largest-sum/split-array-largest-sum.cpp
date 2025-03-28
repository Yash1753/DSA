class Solution {
public:
    int part(vector<int>&a , int maxSum){
        long long sum = 0;
        int partition = 1;
        int n = a.size();
        for(int i= 0 ; i<n;i++){
            if(sum+a[i] <=maxSum){
                sum+=a[i];
            }else{
                partition++;
                sum = a[i];
            }
        }

        return partition;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        //,linear search tle maarega
        /* for(int i = low ; i <= high ; i++){
            if(part(nums,i) == k) return i;
        } */

        //usingbinary search
        int ans = low;
        while(low <=high){
            int mid = low +(high-low)/2;
            
            if(part(nums,mid) <=k ){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};