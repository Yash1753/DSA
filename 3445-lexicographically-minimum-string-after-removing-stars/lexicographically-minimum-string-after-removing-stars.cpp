class Solution {
public:
    struct comp{
        bool operator()(auto &p1, auto &p2){
            if(p1.first == p2.first){
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
    };

    string clearStars(string s) {
        int n = s.length();

        priority_queue<pair<char,int>, vector<pair<char,int>>, comp> pq;
        for(int i = 0; i < n ;i++){
            if(s[i] != '*'){
                pq.push({s[i],i});
            }else{
                int idx = pq.top().second;
                pq.pop();
                s[idx] = '*';

            }

        }

        string ans = "";
        for(auto ch : s){
            if(ch != '*'){
                ans+= ch;
            }
        }

        return ans;

    }
};