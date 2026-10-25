
class Solution {
public:
    bool f(vector<int>& have, vector<int>& needed) {
        for (int i = 0; i < 256; i++) {
            if (have[i] < needed[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n) return "";
        vector<int> have(256, 0);
        vector<int> needed(256, 0);
        for (char c : t) {
            needed[c]++;
        }
        int low = 0;
        int start = 0;
        int res = INT_MAX;
        for (int high = 0; high < n; high++) {
            have[s[high]]++;
            while (f(have, needed)) {
                int length = high - low + 1;
                if (res > length) {
                    res = length;
                    start = low;
                }
                have[s[low]]--;
                low++;
            }
        }
        return res == INT_MAX ? "" : s.substr(start, res);
    }
};