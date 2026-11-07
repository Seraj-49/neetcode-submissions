
class Solution {
public:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n + m);
        int i = 0, j = 0, k = 0;
        while(i < n && j < m) {
            if(nums1[i] <= nums2[j]) {
                ans[k] = nums1[i];
                i++;
            } else {
                ans[k] = nums2[j];
                j++;
            }
            k++;
        }
        while(i < n) {
            ans[k] = nums1[i];
            i++;
            k++;
        }
        while(j < m) {
            ans[k] = nums2[j];
            j++;
            k++;
        }
        return ans;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans = merge(nums1, nums2);
        int n = ans.size();
        if(n % 2 != 0) {
            return (double)ans[n / 2];
        } else {
            return ((double)ans[n / 2 - 1] + ans[n / 2]) / 2.0;
        }
    }
};
