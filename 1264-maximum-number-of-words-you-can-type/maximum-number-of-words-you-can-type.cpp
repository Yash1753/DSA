class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string>temp;

        int i = 0;
        int j = 0;

        while(j < text.size()){
            if(text[j] == ' '){
                temp.push_back(text.substr(i,j-i));
                i = j+1;
            }
            j++;
        }

        temp.push_back(text.substr(i,j-i));

       /*  for(auto it: temp){
            cout << it << " ";
        } */


        unordered_set<char>mp;
        for(auto ch : brokenLetters){
            mp.insert(ch);
        }
        int cnt = temp.size();
        for(auto it : temp){
            for(auto ch : it ){
                if(mp.count(ch) != 0){
                    cnt--;
                    break;
                }
            }
        }
        return  cnt;
    }
};