class Solution {
public:

    bool fn(int mid,vector<int>& bloomDay, int m, int k ){
        int cnt = 0; // adj flowers
        int total =0; //bouqet

        for(int i = 0 ; i < bloomDay.size() ; i++){
            if(bloomDay[i] <= mid) cnt++;
            else{
                total += cnt/k;
                cnt = 0;
            }
        }
        total += cnt/k;
        return total >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        //bnane h m bouqet using k adjacent flowers
        int low = 1;
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(fn(mid,bloomDay,m,k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};