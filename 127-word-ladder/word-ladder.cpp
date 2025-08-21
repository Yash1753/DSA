class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //string to string think bfs 
        unordered_set<string>wordBank(wordList.begin(),wordList.end());
        if(!wordBank.count(endWord)) return 0;
        unordered_set<string>visited;

        queue<string>q;
        q.push(beginWord);
        visited.insert(beginWord);
        int level = 1;
        string check = "abcdefghijklmnopqrstuvwxyz";
        while(!q.empty()){
            int N = q.size();
            while(N--){
                auto top = q.front();
                q.pop();

                if(top == endWord) return level;

                for(auto ch : check){
                    for(int i = 0 ; i < top.size() ; i++){
                        string tf = top;
                        tf[i] = ch;

                        if(visited.find(tf) == visited.end() && wordBank.find(tf) != wordBank.end() ){
                            q.push(tf);
                            visited.insert(tf);
                        }
                    }
                }

            }
            level++;
        }

        return 0;
    }
};