class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int st = 0,end = n-1;
        int maxi = 0;
        while(st < end) {
            int length = min(heights[st],heights[end]);
            int width = end - st;
            int area = length * width;
            if(heights[st] < heights[end]) {
                st++;
            } else {
                end--;
            }
            maxi = max(maxi,area);
        }
        return maxi;
        }
};
