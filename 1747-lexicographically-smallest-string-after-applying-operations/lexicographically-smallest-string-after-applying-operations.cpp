class Solution {
public:

    void rotate(string &s , int b){
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.begin()+b);
        reverse(s.begin()+b,s.end());
    }

    string findLexSmallestString(string s, int a, int b) {
        //pattern find 
        //cycled back toh mod to 10 h
        // lexicographically smallest string you can obtain by applying the above operations any number of times on s. toh yaha bfs lg jayega

        string smallest =  s;
        queue<string>q;
        unordered_set<string>st;
        q.push(s);
        st.insert(s);

        //applying bfs with functions

        while(!q.empty()){
            string curr = q.front();
            q.pop();

            if(curr < smallest) smallest = curr;

            //adding a to odd
            string temp = curr;
            for(int i = 1 ; i < temp.size() ; i+=2){
                //capture odd indices
                //char to int and then int to char
                temp[i] = ((temp[i]-'0' + a)%10) + '0';
            }

            if(!st.count(temp)){
                q.push(temp);
                st.insert(temp);
            }

            //rotate
            rotate(curr,b);
            if(!st.count(curr)){
                q.push(curr);
                st.insert(curr);
            }
            
        }

        return smallest;

    }
};