class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = INT_MIN;
        int sum = 0;
        for(int i=0;i<n;i++) {
            maxi = max(maxi,piles[i]);
        }
        int low = 1, high = maxi;
        while(low <= high) {
            int mid = (low + high) / 2;
            long long ans = 0;
            for(int i=0;i<n;i++) {
                int time = (piles[i] + mid - 1) / mid;
                ans += time;
            }
            if(ans <= h) {
                high =  mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low; 
    }
};
