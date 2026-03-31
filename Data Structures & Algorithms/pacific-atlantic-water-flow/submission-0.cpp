class Solution {
public:

    void dfs(int r, int c, int previous_val, vector<vector<int>>& heights, set<pair<int,int>>& visited){

        if(r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size() || heights[r][c] < previous_val || visited.count({r,c})){
            return;
        }

        visited.insert({r,c});
        dfs(r-1, c, heights[r][c], heights, visited);
        dfs(r+1, c, heights[r][c], heights, visited);
        dfs(r, c-1, heights[r][c], heights, visited);
        dfs(r, c+1, heights[r][c], heights, visited);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        set<pair<int,int>> pacific;

        set<pair<int,int>> atlantic;

        vector<vector<int>> results;

        int rows = heights.size();
        int cols = heights[0].size();

        for(int c = 0; c < cols; c++){
            dfs(0, c, heights[0][c], heights, pacific);
            dfs(rows-1, c, heights[rows-1][c], heights,  atlantic);
        }

        for(int r = 0; r < rows; r++){
            dfs(r, 0, heights[r][0], heights, pacific);
            dfs(r, cols-1, heights[r][cols-1], heights, atlantic);
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(pacific.count({i,j}) && atlantic.count({i,j})){
                    results.push_back({i,j});
                }
            }
        }

        return results;   
    }
};
