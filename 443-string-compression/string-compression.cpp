class Solution {
public:
    int compress(vector<char>& chars) {
        //2pointer rkhte h // index update k kaam aayega
        int index = 0;
        int prev = chars[0];
        int cnt = 1;

        for(int i = 1 ; i< chars.size() ; i++){
            if(prev == chars[i]){
                cnt++;
            }
            else{
                chars[index] = prev;
                index++;
                if(cnt > 1){
                    int start = index;
                    while(cnt){
                        chars[index++] = cnt%10 +'0';
                        cnt /=10;
                    }
                    reverse(chars.begin() + start , chars.begin() + index);
                }
                prev= chars[i];
                cnt = 1;
            }
        }
        chars[index++] = prev;
        if(cnt > 1){
            int start = index;
                while(cnt){
                    chars[index++] = cnt%10 +'0';
                    cnt /=10;
                }
            reverse(chars.begin() + start , chars.begin() + index);
        }
        return index;


    }
};
