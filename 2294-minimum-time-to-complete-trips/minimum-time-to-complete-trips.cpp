class Solution {
public:
    bool isValid(vector<int>& time, int k, long long  mid){
        long long trips = 0;

        for(auto & t : time){
            trips += mid/t; 
        }
        return trips>=k;

    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long s = 0;
        long long e = (long long)*max_element(time.begin(),time.end()) * totalTrips;
        while(s < e){
            long long mid = s + (e-s)/2;

            if(isValid(time,totalTrips,mid)){
                e = mid;
            }else{
                s = mid+1;
            }
        }

        return s;
    }
};