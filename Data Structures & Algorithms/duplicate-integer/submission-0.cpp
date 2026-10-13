class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) {
            int count = 0;
            for(int j=i;j<n;j++) {
              if(nums[i] == nums[j]) count++;
              if(count > 1) {
              return true;
              break;
              }
            }
        }
        return false;
    }
};