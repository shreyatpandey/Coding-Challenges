//Time Complexity :- O(n+m) where n is the number of node with m being the number of edges
//Space Complexity:- O(n) this space is because of the visited dictionary that is used
//Approach:- BFS
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
     if ( node == NULL )
         return NULL;
     unordered_map<Node*,Node*>visited ;
     queue<Node*>Q;
     Q.push(node);
     visited[node] = new Node(node->val,vector<Node*>{});
     while(Q.size())
     {
         Node* temp = Q.front();
         Q.pop();
         for(auto x:temp->neighbors)
         {
             if (visited.count(x) == 0)
             {
                 visited[x] = new Node(x->val,vector<Node*>{});
                 Q.push(x);
             }
             /* Brain-fart here/brain is tired , cannot proceed */
             visited[temp]->neighbors.emplace_back(visited[x]);
             
         } 
     }
     return visited[node];
        
    }
};
