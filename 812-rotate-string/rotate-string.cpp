class Solution {
public:
    bool rotateString(string s, string goal) {
        int n  = s.length();
        int m  = goal.length();
        if(n != m)return false;
        string total = s+s;

        if(total.find(goal) != string::npos){
            return true;
        }
        


        return false;;
    }
};