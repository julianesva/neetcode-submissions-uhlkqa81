class Solution {
public:
    string longestPalindrome(string s) {

        string longest_pal = "";
        int longest_pal_size = 0;

        int string_s = s.size();
        for(int i = 0; i < string_s; i++){
            int l = i; 
            int r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(r - l + 1 > longest_pal_size){
                    longest_pal = s.substr(l, r-l+1);
                    longest_pal_size = longest_pal.size();
                }
                l--;
                r++;
            }

            l = i;
            r = i + 1; 
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                
                if(r - l + 1 > longest_pal_size){
                    longest_pal = s.substr(l, r-l+1);
                    longest_pal_size = longest_pal.size();
                }
                l--;
                r++;
            }
            
        }

        return longest_pal;  
    }
};
