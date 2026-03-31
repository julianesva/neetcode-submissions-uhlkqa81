class Solution {
public:
    string minWindow(string s, string t) {
        if(t == "") return "";

        unordered_map<char, int> countT;
        unordered_map<char, int> windowS;

        for(char chr : t){
            countT[chr]++;
        }

        int have = 0; 
        int need = countT.size();
        int l = 0;
        pair<int,int> response {-1, -1};
        int resp_length = INT_MAX;
        

        for(int r = 0; r < s.size(); r++){
            char c = s[r];
            windowS[c]++;

            if(countT.count(c) && windowS[c] == countT[c]){
                have++;
            }

            while(have == need){
                if((r - l + 1) < resp_length){
                    resp_length = r - l + 1;
                    response = {l, r};
                }

                windowS[s[l]]--;
                if(countT.count(s[l]) && windowS[s[l]] < countT[s[l]]){
                    have--;
                }
                l++;
            }
        }

        return resp_length == INT_MAX ? "" : s.substr(response.first, resp_length);
        
    }
};
