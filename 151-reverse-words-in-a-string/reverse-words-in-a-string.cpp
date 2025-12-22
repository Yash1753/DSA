class Solution {
public:
    string reverseWords(string s) {
        vector<string>st;

        int i = 0;
        int j  = 0;
        

        while(!s.empty() && s.back() == ' '){
            s.pop_back();
        }

        while(s[i] == ' '){
            i++;
            j++;
        }
        int n = s.size();
        while(j < n){
            if(s[j] == ' '){
               if (i < j) {
                    st.push_back(s.substr(i, j - i));
                }
                j++;
                i = j;
            }else{
                j++;
            }
        }

        if( i < j ){
            st.push_back(s.substr(i,j-i));
        }


        reverse(st.begin(),st.end());

        string ans;
        for (int k = 0; k < st.size(); k++) {
            ans += st[k];
            if (k != st.size() - 1) ans += " ";
        }

        return ans;
    }
};