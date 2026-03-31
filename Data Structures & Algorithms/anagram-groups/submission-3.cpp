class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        if(strs.size() == 1){
            return {{strs}};
        }
        vector<vector<string>> answer;
        unordered_map<string, vector<string>> anagrams;

        int char_sum;
        for(const auto& str : strs){
            vector<int> count(26,0);
            for(const auto& chr : str){
                count[chr - 'a']++;
            }
            string key = to_string(count[0]);
            for(const auto& freq : count){
                key += ',' + to_string(freq);
            }
            anagrams[key].push_back(str);
        }

        for(const auto& anagram : anagrams){
            answer.push_back(anagram.second);
        }

        return answer;
        
    }
};
