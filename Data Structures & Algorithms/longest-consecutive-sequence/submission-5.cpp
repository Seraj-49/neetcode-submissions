class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        unordered_set<int> st;
        for(int i=0;i<n;i++) {
            st.insert(nums[i]);
        }
        for(auto it: st) {
        if(st.find(it-1) == st.end()) {
          int count = 1;
          while(st.find(it+1) != st.end()) {
            it++;
            count++;
          }
          maxi = max(maxi,count);
        }
      }
      return maxi;
    }
};
