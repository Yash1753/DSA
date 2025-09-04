class Solution {
public:
    bool helper(vector<int>& piles, int h, int k){
        int n = piles.size();
        int time = 0;
        
        for(int i = 0 ;i < n ;i++){
            time += ceil((double)piles[i]/(double)k);
            if(time > h) return false;
        }

        
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        //guard h hours m shift maarege 
        //speped - >k
        //agar ok se less than banan she eat all and will not more that hopur 
        //k chaiye

        int s = 1;
        int e= *max_element(piles.begin(),piles.end());
        int ans = 0;
        while(s<e){
            int mid = s + (e-s)/2;
            if(helper(piles,h,mid)){
                ans = mid;
                e = mid;
            }else{
                s = mid+1;
            }

        }
        return s;
        
    }
};