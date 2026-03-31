class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> subsequences(nums.begin(), nums.end());
        int longest_subs = 0; 

        for(int num : subsequences){
            if(!subsequences.count(num-1)){
                int curr = num; 
                int count = 1;

                while(subsequences.count(curr + 1)){
                    curr++;
                    count++;
                }
                longest_subs = max(longest_subs, count);
            }
        }

        return longest_subs;
    }

};
