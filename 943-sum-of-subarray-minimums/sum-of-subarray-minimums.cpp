class Solution {
public:
int MOD = (int)1e9+7;

    vector<int>psee(vector<int>&arr){
        int n = arr.size();
        stack<int>st;
        vector<int>pse(n);

        for(int i = 0 ; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            pse[i] = st.empty() ? -1:st.top();

            st.push(i);
        }

        return pse;
    }
    vector<int>nse(vector<int>&arr){
        int n = arr.size();
        stack<int>st;
        vector<int>nex(n);

        for(int i = n-1 ; i >=0  ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            nex[i] = st.empty()? n :st.top();

            st.push(i);
        }

        return nex;
    }


    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;
        //non optimized version
        /* for(int i = 0 ; i < n ; i++){
            int mini= arr[i];
            for(int j = i ; j < n ; j++){
                mini = (min(mini,arr[j]));
                total = (total+mini)%MOD;
            }
        } */


        //optimization

        //stack leke get pse and nse isme pse m equal bhi lege so beat edge case 
        vector<int>pre = psee(arr);
        vector<int>nex = nse(arr);
        
        for(int i = 0 ; i < n ; i++){
            long long left = i-pre[i];
            long long right = nex[i]-i;
            total = (total + arr[i] * left % MOD * right % MOD) % MOD;
        }
      

        return total;
    }
};