class Solution {
public:
int N;
   

    void lis(vector<int>& nums, int curr , int prev, vector<int>&result, vector<int>&temp){
        if(curr >= N){
            if(temp.size() > result.size()){
                result = temp;
                //temp.clear();
            }
            return;
        }

        int take = 0;
        
        
        if(prev == -1 || nums[curr]%nums[prev] == 0 ){
            temp.push_back(nums[curr]);
            lis(nums,curr+1,curr,result,temp);
            temp.pop_back();
        }

        lis(nums,curr+1,prev,result,temp);


        

        
    }


    vector<int> largestDivisibleSubset(vector<int>& nums) {
      N = nums.size();
      if(N == 1) return {nums[0]};
      sort(nums.begin(),nums.end());
    vector<int>cnt(N,1);
    vector<int>ind(N,-1);
    int maxInd = 0;
    int maxL = 1;
    for(int i = 1 ; i < N ; i++){
        for(int j = 0 ; j < i ; j++){
            if(nums[i] % nums[j] == 0){
                if(cnt[i] < cnt[j]+1){
                    cnt[i] = cnt[j]+1;
                    ind[i] = j;
                }

                if(cnt[i] > maxL){
                maxL = cnt[i];
                maxInd = i;

            }
                
            }

           
        }
    }

    vector<int>result;

    while(maxInd!= -1){
        result.push_back(nums[maxInd]);
        maxInd = ind[maxInd];
    }

    return result;
    }
};