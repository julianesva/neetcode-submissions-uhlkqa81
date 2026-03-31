class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int final_product = 1; 
        
        int zero_count = 0;

        for(int num : nums){
            if(num == 0){
                zero_count++;
                continue;
            }
            final_product *= num;
        }

        if(zero_count > 1){
            vector<int> result(nums.size(), 0);
            return result; 
        }

        vector<int> result; 
        for(int num : nums){
            if(zero_count){
                if(num != 0){
                    result.push_back(0);
                    continue;
                }
                result.push_back(final_product);
            }
            else{
                result.push_back(final_product/num);   
            } 
        }

        return result;
    }
};
