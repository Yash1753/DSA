class Solution {
public:
    char mid;
    string ans;

    bool solve(int i, string s, vector<int>&vis, string &target, bool flag){
        if(s.size() == target.size()/2){
            string p = s;
            reverse(s.begin(),s.end());

            if(target.size()%2){
                p+= mid;
            }
            p+=s;
            if(p > target){
                ans = p;
                
                return true;
            }
            
            return false;
        }


        //har ek character se banai [degi]
        for(int j = 0 ; j < 26 ; j++){
            if(vis[j] == 0) continue;

            if(!flag && j + 'a' < target[i]) continue;

            vis[j]--;
            bool newFlag = flag;
            s+=j+'a';

            if(target[i] < j+'a' ) newFlag = true;

            if(solve(i+1,s,vis,target,newFlag)) return true;

            vis[j]++;
            s.pop_back();
        }
        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        //kya soch skte h

        //pehle dekho if possible to make palindrome
        int n = s.length();
        vector<int>vis(26,0);
        for(char &c : s){
            vis[c - 'a']++;
        }

        int odd = 0;
        for(int i = 0 ; i < 26 ; i++){
            
            if(vis[i]%2){
                odd++;
                mid = i + 'a';
            }
             if(odd > 1){
                return "";
            }
            vis[i] = vis[i]/2;
           

        }
        

       
        ans = "";
        string temp = "";
        int i = 0;
        return solve(i,temp,vis,target,false)?ans:"";
    }
};