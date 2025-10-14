class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int i = 0 , j = n-1;
        int maxArea = 0;
        while(i <= j){
            int w = j-i;
            int h = min(height[j], height[i]);

            int area = w*h;
            maxArea = max(maxArea, area );

            if(height[j] > height[i]) i++;
            else j--;
        
        }

        return maxArea;
    }
};