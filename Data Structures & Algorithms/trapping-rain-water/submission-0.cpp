class Solution {
public:
    int trap(vector<int>& height) {
       int n = height.size();
        int water = 0;
        int maxi1 = 0, maxi2 = 0;
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        for(int i = 0; i < n; i++) {
            maxi1 = max(maxi1, height[i]);
            leftMax[i] = maxi1;
        }
        for(int i = n - 1; i >= 0; i--) {
            maxi2 = max(maxi2, height[i]);
            rightMax[i] = maxi2;
        }
        for(int i = 0; i < n; i++) {
            int trapped = min(leftMax[i], rightMax[i]) - height[i];
            if(trapped > 0)  water += trapped;
        }
        return water;  
    }
};
