class Solution {
public:

    bool fn(int mid, vector<int>& piles, int h){
        bool canEat = false;

        long long timetoEat = 0;

        for(int i = 0; i < piles.size();i++){
            timetoEat += ceil((double)piles[i]/(double)mid);
        }

        canEat = timetoEat <= h;

        return canEat;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        //h hours k time h ji
        //k hme find krna h minimum ki vo sb kaha jaye
        //1 hr m ek slot hi kaha skti

        //range lelo

        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = INT_MAX;

        while(low <=high){
            int mid = low + (high-low)/2;

            if(fn(mid,piles,h)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};