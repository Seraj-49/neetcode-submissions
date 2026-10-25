
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi = 0;
        int low = 0;
        unordered_map<char, int> mp;
        for (int high = 0; high < n; high++) {
            mp[s[high]]++;
            while (mp[s[high]] > 1) {
                mp[s[low]]--;
                
                if (mp[s[low]] == 0) {
                    mp.erase(s[low]);
                }
                low++;
            }
            int length = high - low + 1;
            maxi = max(maxi, length);
        }
        return maxi;
    }
};