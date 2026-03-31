/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return {};

        unordered_map<Node*, Node*> oldToNew;
        queue<Node*> adj_nodes;

        oldToNew[node] = new Node(node->val);
        adj_nodes.push(node);


        while(!adj_nodes.empty()){
            Node* curr_node = adj_nodes.front();
            adj_nodes.pop();

            for(const auto& neigh : curr_node->neighbors){
                if(oldToNew.find(neigh) == oldToNew.end()){
                    oldToNew[neigh] = new Node(neigh->val);
                    adj_nodes.push(neigh);
                } 
                oldToNew[curr_node]->neighbors.push_back(oldToNew[neigh]);
            }
        }

        return oldToNew[node];
        
    }
};
