class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        int left = 0,right = n-1;
        int leftMax = 0, rightMax = 0;
        while(left < right) {
            leftMax = max(leftMax,height[left]);
            rightMax = max(rightMax,height[right]);
            if(leftMax < rightMax) {
                int trapped = leftMax - height[left];
                water += trapped;
                left++;
            } else {
                int trapped = rightMax - height[right];
                water += trapped;
                right--;
            }
        }
        return water;
    }
};