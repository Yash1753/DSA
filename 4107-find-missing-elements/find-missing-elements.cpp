class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int lowest = *min_element(nums.begin(),nums.end());
        int highest = *max_element(nums.begin(),nums.end());

        int number_of_elements = highest - lowest + 1;

        int n = nums.size();

        unordered_set<int>s(nums.begin(),nums.end());

        vector<int>ans;
        for(int i = lowest ; i <= highest ; i++){
            if(s.count(i) == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};