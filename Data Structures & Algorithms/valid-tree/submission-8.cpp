class Solution {
public:

    bool tree_validator(int curr, int parent, vector<vector<int>>& adj, vector<bool>& visited){
        if(visited[curr]){
            return false;
        }

        visited[curr] = true; 

        for(int neigh: adj[curr]){
            if(neigh == parent) continue;
            if(!tree_validator(neigh, curr, adj, visited)){
                return false;
            }
        }
        return true;
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
        if(!tree_validator(0, -1, adj, visited)){
            return false;
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
