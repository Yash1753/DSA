class Solution {
public:
    typedef vector<double> D;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;

        // Priority queue stores a tuple (fraction, numerator index, denominator index)
        priority_queue<vector<double>, vector<vector<double>>, greater<vector<double>>> pq;

        // Initially push the fractions (arr[i] / arr[n-1])
        for (int i = 0; i < n - 1; i++) {
            pq.push({(double)arr[i] / arr[n - 1], (double)i, (double)(n - 1)});
        }

        // We need to pop and push to find the kth smallest fraction
        int smallest = 1;
        while (smallest < k) {
            // Pop the smallest fraction
            auto front = pq.top();
            pq.pop();

            int i = front[1]; // Numerator index
            int j = front[2] - 1; // Denominator index

            // Push the next fraction from the same numerator
            if (j > i) {
                pq.push({(double)arr[i] / arr[j], (double)i, (double)j});
            }
            smallest++;
        }

        // The top of the priority queue now holds the kth smallest fraction
        auto top = pq.top();
        ans.push_back((int)arr[(int)top[1]]);
        ans.push_back((int)arr[(int)top[2]]);
        return ans;
    }
};
