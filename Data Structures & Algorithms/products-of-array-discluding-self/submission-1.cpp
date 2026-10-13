class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> post(n);
        int prefix = 1;
        for(int i=0;i<n;i++) {
          pre[i] = prefix;
          prefix *= nums[i];
        }
        int suffix = 1;
        for(int j=n-1;j>=0;j--) {
            post[j] = suffix;
            suffix *= nums[j];
        }
        for(int i=0;i<n;i++) {
            nums[i] = pre[i] * post[i];
        }
         return nums;
    }
};
