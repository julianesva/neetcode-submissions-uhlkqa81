class Solution {
public:

    void tree_validator(int curr, vector<vector<int>>& adj, vector<bool>& visited){
        if(visited[curr]){
            return;
        }

        visited[curr] = true; 
        
        for(int neigh: adj[curr]){
            tree_validator(neigh, adj, visited);
        }

    }
    bool validTree(int n, vector<vector<int>>& edges) {

        if(n <= edges.size()){
            return false;
        }
        // adjacency list to store neighbors
        vector<vector<int>> adj(n); 
        vector<bool> visited(n, false);

        // iteration through the edges vector to make the adjacency list
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        // Iterate only one time from the first node to see if all the nodes are reachable. 
        for(int j = 0; j < 1; j++){
            tree_validator(j, adj, visited);
        }

        // if there is one false in the visited vector that means that you can not reach the entire graph and is not a valid tree. 
        for(bool value: visited){
            cout<<value<<endl;
            if(!value){
                
                return false;
            }
        }

        return true; 

    }
};
