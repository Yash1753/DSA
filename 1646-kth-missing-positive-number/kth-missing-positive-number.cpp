class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int maxi = *max_element(arr.begin(),arr.end());
        vector<int>hash(maxi + 1,0);
        int n = arr.size();

        for(int i = 0 ; i < n ; i++){
            hash[arr[i]]++;
        }

        int ans = -1;
        for(int i = 1 ; i <= hash.size()-1;i++){
            if(hash[i] == 0){
                k--;
                if(k==0){
                    ans = i;
                }
            }
        }

        if(ans == -1 && k>0){
            ans = k+maxi;
        }

        return ans;

    }
};