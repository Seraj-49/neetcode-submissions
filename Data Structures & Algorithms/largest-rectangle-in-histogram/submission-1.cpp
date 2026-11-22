class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();
        stack<int> st;
        int maxi = 0;
        int curr,width;
        for(int i = 0; i <= n; i++) {
           if(i == n) {
             curr = 0;
            } else {
            curr = heights[i];
          }
           while(!st.empty() && heights[st.top()] > curr) {
                int height = heights[st.top()];
                st.pop();
                if(st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }
                maxi = max(maxi, height * width);
            }
            st.push(i);
        }
        return maxi;
    }
};
