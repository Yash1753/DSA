class Solution {
public:
    int n,m;
    map<pair<int,int>,int>mpp;
    int helper(int i, vector<int>&a, vector<int>&b, int prev){
        if(i == n) return 0;
        int res1 = 1e9+1;

        if(mpp.find({i,prev})!= mpp.end()) return mpp[{i,prev}];
        if(a[i] > prev){
            res1 = helper(i+1,a,b,a[i]);
        }
        
        int res2 = 1e9+1;
        auto ub = upper_bound(b.begin(), b.end(), prev);
        if(ub != b.end()){
            res2 = 1 + helper(i+1, a,b ,b[ub-b.begin()] );
        }

        return mpp[{i,prev}] = min(res1,res2);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        //2 cases khellne pdeg replace k ek jb essential ek mxa k
        sort(arr2.begin(),arr2.end());
        n = arr1.size();
        m = arr2.size();
        mpp.clear();
        int result = helper(0,arr1,arr2, INT_MIN) ;
        return result == 1e9+1 ? -1 : result;
    }
};