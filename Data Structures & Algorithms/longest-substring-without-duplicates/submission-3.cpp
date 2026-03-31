class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> mp; 
        int long_subst = 0; 
        int l = 0; 

        for(int r = 0; r < s.size(); r++){
            if(mp.count(s[r])){
                l = max(mp[s[r]] + 1, l);
            }
            mp[s[r]] = r;
            long_subst = max(r - l + 1, long_subst);
        }

        return long_subst;
        
    }
};
