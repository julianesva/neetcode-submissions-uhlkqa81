class Solution {
public:

    void island_finder(vector<vector<char>>& grid, int r, int c){

        queue<pair<int, int>> adjacent_nodes;

        vector<pair<int, int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

        adjacent_nodes.push({r, c});

        while(!adjacent_nodes.empty()){
            int r = adjacent_nodes.front().first;
            int c = adjacent_nodes.front().second;
            adjacent_nodes.pop();

            for(const auto& dir : directions){
                int dr = r + dir.first;
                int dc = c + dir.second;
                
                if(dr < grid.size() && dc < grid[0].size() && grid[dr][dc] == '1'){
                    grid[dr][dc] = 0;
                    adjacent_nodes.push({dr, dc});
                }
            }
        }


    }
    int numIslands(vector<vector<char>>& grid) {

        int island_count = 0;
        for(int r = 0 ; r < grid.size(); r++){
            for(int c = 0 ; c < grid[0].size(); c++){
                cout<<"current node: "<<grid[r][c]<<endl;
                if(grid[r][c] == '1'){
                    island_count++;
                    cout<<"Island Count: "<<island_count<<endl;
                    grid[r][c] = 0;
                    island_finder(grid, r, c);
                }
            }
        }
        return island_count;
    }
};
