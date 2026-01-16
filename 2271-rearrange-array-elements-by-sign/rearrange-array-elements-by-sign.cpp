class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;

        for(auto &it : nums){
            if(it < 0){
                neg.push_back(it);
            }else{
                pos.push_back(it);
            }
        }

        int i = 0;
        int j = 0;
        int index = 0;
        while(i < pos.size() || j < neg.size()){
            nums[index++] = pos[i++];
            nums[index++] = neg[j++];
        }
        return nums;
    }
};