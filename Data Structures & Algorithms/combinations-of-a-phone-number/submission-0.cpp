class Solution {
private:
    unordered_map<char, string> dig_comb{
        {'2', "abc"}, {'3', "def"},
        {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

    vector<string> resp;
public: 
    void all_comb(int i, string currstr, string digits) {

        if(currstr.size() == digits.size()){
            resp.push_back(currstr);
            return;
        }

        string chars = dig_comb[digits[i]];
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
