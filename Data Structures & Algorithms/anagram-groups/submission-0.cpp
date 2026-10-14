class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> ans;
        for(int i=0;i<n;i++) {
            string s = strs[i];
            sort(s.begin(),s.end());
            ans[s].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto it: ans) {
            res.push_back(it.second);
        }
        return res;
    }
};
