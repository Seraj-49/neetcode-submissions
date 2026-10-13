class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> ans(26,0);
        if(m != n) return false;
        for(int i=0;i<n;i++) {
            ans[s[i] - 'a']++;
            ans[t[i] - 'a']--;
        }
        for(int i=0;i<ans.size();i++) {
            if(ans[i] != 0) return false;
        }
        return true;
    }
};
