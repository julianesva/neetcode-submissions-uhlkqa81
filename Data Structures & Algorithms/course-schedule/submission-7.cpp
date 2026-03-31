class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int curr){
        if(adj[curr].empty()){
            return true;
        }
        
        if(visited[curr]){
            return false;
        }

        visited[curr] = true;

        for(int req : adj[curr]){
            if(!dfs(adj, visited, req)){
                return false;
            }
        }
        adj[curr].clear();
        visited[curr] = false;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        if(prerequisites.size() == 0){
            return true;
        }

        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses, false);

        for(const auto& pre : prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }

        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(!dfs(adj, visited, i)){
                    return false;
                }
            }
        }
        return true;
    }
};
