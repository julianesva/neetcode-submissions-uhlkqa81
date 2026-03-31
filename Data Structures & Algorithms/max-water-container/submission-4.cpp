class Solution {
public:
    int maxArea(vector<int>& heights) {

        int left = 0; 
        int right = heights.size()-1; 
        int max_water = 0; 

        while(left < right){
            int minimum = min(heights[left], heights[right]);
            int water_cap = minimum * (right - left);
            max_water = max(max_water, water_cap);

            if(heights[left] > heights[right]){
                right--; 
            }
            else{ 
                left++; 
            }
        }

        return max_water;
        
    }
};
