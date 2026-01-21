class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int mini = INT_MAX;
        int i = 0 ; int j = 0;
        int n = cards.size();
        unordered_map<int,int>mpp;
        while(j < n){
            if(mpp.count(cards[j])){
                mini = min(mini, j-mpp[cards[j]] + 1);
            }
            mpp[cards[j]] = j;
            j++;
        }

        return mini==INT_MAX ? -1 : mini;

    }
};