class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        string s = "";
        s+= chars[0];
        while(j < n){
            if(chars[i] == chars[j]){
                cnt++;
            }else{
                if(cnt > 1){
                    string t = "";
                    while(cnt){
                        t+= to_string(cnt%10);
                        cnt = cnt/10;
                        
                    }
                    reverse(t.begin(), t.end());
                    s+=t;
                }
                
                s+= chars[j];
                cnt = 1;
                i = j;
            }
            j++;
        }
       if(cnt > 1){
                    string t = "";
                    while(cnt){
                        t+= to_string(cnt%10);
                        cnt = cnt/10;
                        
                    }
                    reverse(t.begin(), t.end());
                    s+=t;
                }

        for(int i = 0 ; i < s.length() ; i++ ){
            char ch = s[i];
            chars[i] = ch;
            
        }
        return s.size();
    }
};