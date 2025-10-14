class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int maxi = *max_element(arr.begin(),arr.end());
        vector<int>hash(maxi,0);

        for(int i = 0 ; i < arr.size() ; i++){
            hash[arr[i]-1] = 1;
        }

        int cnt = 0;

        for(int i = 0 ; i < maxi ; i++){
            if(hash[i] == 0){
                cnt++;
            }
            if(cnt == k){
                return i+1;
            }

        }

       return maxi + k - cnt ;

    }
};