class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        
        int maxLen = 0, left = 0, maxCount = 0;
        for(int right=0; right<s.size(); right++)
        {
            mp[s[right]]++;
            maxCount = max(maxCount, mp[s[right]]);
            int windowLen = right - left + 1;
            if(windowLen - maxCount > k)
            {
                mp[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
