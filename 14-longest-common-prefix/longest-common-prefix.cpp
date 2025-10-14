class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string word1 = strs[0];
        string word2 = strs[strs.size()-1];

        int i =0, j = 0;
        string pre = "";
        while(i < word1.length() && j < word2.length()){
            if(word1[i] == word2[j]){
                pre.push_back(word1[i]);
                i++;
                j++;
            }else{
                break;
            }
        }

        return pre;
    }
};