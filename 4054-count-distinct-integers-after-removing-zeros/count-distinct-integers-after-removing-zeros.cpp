class Solution {
public:
    long long countDistinct(long long n) {
        //t 1 to n
        long long total = 0;
        long long power  =9;

        string x = to_string(n);
        int size = x.size();

        for(int i = 1 ; i < size ; i++){
            total += power;
            power *=9;
        }

        for(int i = 0 ; i < size ; i++){
            int digit = x[i] - '0';
            for(int d = 1 ; d < digit ; d++){
                int rem = size -i -1;
                total += pow(9,rem);
            }
            if(digit == 0) break;
            if(i == size -1) total += 1;;
        }

        return total;

    }
};