class Solution {
public:
    typedef long long ll;
    ll formula(ll count, ll x){
        return (count*x) - (count*(count+1))/2;
    }
    int maxValue(int n, int index, int maxSum) {
        //index p max daalna h
        // left sum and rgiht sum laan suvh that no value diffis greater than 1
        
        ll l = 1;
        ll r  =maxSum;

        ll result;

        while(l <=r){
            ll mid = l + (r-l)/2;

            //--- left k late h // sum of consect + number of 1
            ll leftCount = min((ll)index,mid-1);
            ll left = formula(leftCount, mid);
            left += max((ll)0,index- (mid -1));

            //same right k liye
            ll rightCount = min((ll)n-index-1,mid-1);
            ll right = formula(rightCount, mid);
            right += max((ll)0,n-index-1- (mid -1));

            //calc

            ll tot = left + right + mid;
            if(tot <= maxSum){
                result = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return result;
    }
};