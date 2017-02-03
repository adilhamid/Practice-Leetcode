/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {

private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> myMap;
    
public:
//DFS Solution to the graph cloning 
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        
        if(myMap.find(node) == myMap.end()){
            myMap[node] = new UndirectedGraphNode(node->label);
            for(UndirectedGraphNode* nodes: node->neighbors){
                myMap[node]->neighbors.push_back(cloneGraph(nodes));
            }
        }
        
        return myMap[node];
        
        
    }
    
//BFS Solution to the graph cloning 
    UndirectedGraphNode *cloneGraphBFS(UndirectedGraphNode *node) {
        
        if(!node) return NULL;
        
        UndirectedGraphNode * newNode = new UndirectedGraphNode(node->label);
        myMap[node] = newNode;
        
        queue<UndirectedGraphNode*> myQueue;
        myQueue.push(node);
        
        while(!myQueue.empty()){
            UndirectedGraphNode * temp = myQueue.front();
            myQueue.pop();
            
            for(auto neigh: temp->neighbors){
                
                if (myMap.find(neigh) == myMap.end()) {
                    UndirectedGraphNode* neigh_copy = new UndirectedGraphNode(neigh -> label);
                    myMap[neigh] = neigh_copy;
                    myQueue.push(neigh);
                }
                myMap[temp]->neighbors.push_back(myMap[neigh]);
                
            }
        }
    
        return newNode;
        
    }

};