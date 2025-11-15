class Solution {
public:

    bool check(long long time, vector<int>&d, vector<int>&r){
        long long w1 = time - time/r[0];
        long long w2 = time - time/r[1];

        if(d[0] > w1 || d[1] > w2) return false;

        long long checker = time - time/lcm(r[0],r[1]);

        return checker >= (d[0] + d[1]);
    }
    long long minimumTime(vector<int>& d, vector<int>& r) {
        //2 h {d1,d2},{r1,r2}
        //2 drone and each do i delivaries
        //har hour ek delivary and ek time p ek
        //recharge hote 

        //d denote kr raha delivaries to be made
        //r bta raha recharge time

        long long ans =1e18;
        long long high = 1e18;
        long long low = 0;

        while(low <= high){
            long long mid = high + (low-high)/2;

            if(check(mid,d,r)){
                ans = min(ans,mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};