class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre;
        vector<int> post;
        int prefix = 1;
        for(int i=0;i<n;i++) {
          pre.push_back(prefix);
          prefix *= nums[i];
        }
        int suffix = 1;
        for(int j=n-1;j>=0;j--) {
            post.push_back(suffix);
            suffix *= nums[j];
        }
        
        reverse(post.begin(),post.end());

        for(int i=0;i<n;i++) {
            nums[i] = pre[i] * post[i];
        }
         return nums;
    }
};
