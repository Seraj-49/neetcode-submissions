class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int arr[26] = {0};
        unordered_map<char,int> mp;
        int low = 0;
        int maxFreq = 0;
        int maxi = 0;
        for(int high = 0;high < n;high++) {
            mp[s[high]]++;
            maxFreq = max(maxFreq,mp[s[high]]);
            int length = high - low + 1;
            while(length - maxFreq > k) {
                mp[s[low]]--;
                low++;
                length = high - low + 1;
            } 
             maxi = max(maxi,length);
        }
        return maxi;
    }
};
