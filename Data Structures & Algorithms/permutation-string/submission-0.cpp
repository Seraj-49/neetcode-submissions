
class Solution {
public:
    bool isFrequency(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;
        int freq[26] = {0};
        for (int i = 0; i < n; i++) {
            freq[s1[i] - 'a']++;
        }
        for (int i = 0; i <= m - n; i++) {
            int windowFreq[26] = {0};
            for (int j = i; j < i + n; j++) {
                windowFreq[s2[j] - 'a']++;
            }
            if (isFrequency(freq, windowFreq)) {
                return true;
            }
        }
        return false;
    }
};