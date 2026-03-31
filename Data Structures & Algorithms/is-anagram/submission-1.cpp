class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()){
            return false; 
        }

        vector<int> anag_freq(26, 0);

        for(int i = 0; i < s.size(); i++){
            anag_freq[s[i] - 'a']++;
            anag_freq[t[i] - 'a']--;
        }

        for(int j = 0; j < 26 ; j++){
            if(anag_freq[j] != 0){
                return false;
            }
        }

        return true;
        
    }
};
