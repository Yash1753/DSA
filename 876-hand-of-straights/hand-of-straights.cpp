class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;
        sort(hand.begin(),hand.end());
        unordered_map<int,int>mpp;
        for(auto &it : hand){
            mpp[it]++;
        }
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            
            if(mpp.count(hand[i])){
                int num = hand[i];
                if(mpp.count(num) == 0) continue;
                mpp[num]--;
                if(mpp[num] == 0) mpp.erase(num);
                for(int j = 0 ; j < groupSize-1 ; j++){
                    if(mpp.count(num+1) == 0){
                        return false;
                    }else{
                        mpp[num+1]--;
                        if(mpp[num+1] == 0) mpp.erase(num+1);
                        num = num+1;
                    }
                }
            }
        }

        return true;
    }
};