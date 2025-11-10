class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //words ko acccess easy kri
        unordered_set<string>seen(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);
        int result = 1;
        if(seen.find(endWord) == seen.end()) return 0;
        seen.erase(beginWord);

        
        while(!q.empty()){
            int N = q.size();
            while(N--){
                auto word = q.front();q.pop();
                if(word == endWord) return result;

                for(int i = 0 ; i <word.length() ; i++){
                    auto orig = word;
                    for(char ch = 'a' ; ch <= 'z' ; ch++ ){
                        orig[i] = ch;
                        if(seen.find(orig) != seen.end()){
                            q.push(orig);
                            seen.erase(orig);
                        }
                    }
                }


            }
            result++;

        }

        return 0;
    }
};