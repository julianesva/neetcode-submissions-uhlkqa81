class Solution {
private:
    vector<string> dig_comb{
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> resp;
public: 
    void all_comb(int i, string currstr, string digits) {

        if(currstr.size() == digits.size()){
            resp.push_back(currstr);
            return;
        }

        string chars = dig_comb[digits[i] - '0'];
        for(char c : chars){
            all_comb(i + 1, currstr + c, digits);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        all_comb(0, "", digits);

        return resp;   
    }
};
