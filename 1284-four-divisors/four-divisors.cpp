class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for (int num : nums) {
            int cnt = 0;
            int currSum = 0;

            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    cnt++;
                    currSum += i;

                    if (i != num / i) {
                        cnt++;
                        currSum += num / i;
                    }

                    if (cnt > 4) break; // early exit
                }
            }

            if (cnt == 4) {
                totalSum += currSum;
            }
        }

        return totalSum;
    }
};
