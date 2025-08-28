class Solution {
public:
    int N,M,K;
    int MOD = 1e9+7;
    //it overlapping so put dp 
    //3 changing param
    int dp[51][51][101];
    int solve(int idx, int searchCost, int maxSofar){
        if(idx == N){
            if(searchCost == K) return 1;
            else return 0;
        }

        if(dp[idx][searchCost][maxSofar] != -1) return dp[idx][searchCost][maxSofar];
        int result = 0;
        //now choice fill krege
        for(int i = 1 ; i <= M ;i++){
            //yaha krege value put
            if(i > maxSofar){
                result = (result+ solve(idx+1, searchCost+1, i)) % MOD;
            }else{
                result =  (result + solve(idx+1, searchCost, maxSofar)) % MOD;
            }
        }

        return dp[idx][searchCost][maxSofar] = result;
    }

    int numOfArrays(int n, int m, int k) {
        //yaha choices dekhni pdegi for every index -> array size n and har index p m tak ki value le skta hu
        //choices lgegi and tree diagram bnayegi toh pta chle g and maxSearchCiosr <=k
        N = n;
        M = m;
        K = k;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0); //index,seachcost,maxsofar
    }
};