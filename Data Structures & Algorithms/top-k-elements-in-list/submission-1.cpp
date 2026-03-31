class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> frequencies;
        vector<vector<int>> buckets(nums.size() + 1);
        vector<int> results;

        for(const auto& num : nums){
            frequencies[num]++;
        }

        for(const auto& vpair : frequencies){
            int value = vpair.first;
            int freq = vpair.second;

            buckets[freq].push_back(value);
        }

        for(int i = buckets.size() - 1 ; i >= 0 ; i--){
            for(int val : buckets[i]){
                if(results.size() == k){
                    break;
                }
                results.push_back(val);
            }
        }

        return results;

        
    }
};
