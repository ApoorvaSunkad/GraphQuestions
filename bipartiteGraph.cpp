/*
Given an adjacency list of a graph adj of V no. of vertices having 
0 based index. Check whether the graph is bipartite or not.

Know more about Bipartite Graph: - https://www.geeksforgeeks.org/what-is-bipartite-graph/

Example 1:

Input: 

Output: 1
Explanation: The given graph can be colored 
in two colors so, it is a bipartite graph.
Example 2:

Input:

Output: 0
Explanation: The given graph cannot be colored 
in two colors such that color of adjacent 
vertices differs. 
 

Your Task:
You don't need to read or print anything. Your task is to complete the 
function isBipartite() which takes V denoting no. of vertices and adj 
denoting adjacency list of the graph and returns a boolean value true 
if the graph is bipartite otherwise returns false.
 

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)

Constraints:
1 ≤ V, E ≤ 105

*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

  bool check(int start, int V, vector<int>adj[], int color[]){
        queue<int> q;
	    
	    q.push(start);
	    color[start] = 0;
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        for(auto it:adj[node]){
	            if(color[it] == -1){
	                color[it] = !color[node];
	                q.push(it);
	            }
	            else if(color[it] == color[node]){
	                return false;
	            }
	        }
	    }
	    return true;
}
bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    
	    for(int i = 0; i<V;i++) color[i] = -1;
	    
	    for(int i = 0; i<V;i++){
	        if(color[i]==-1){
	            if(check(i,V,adj,color) == false){
	                return false;
	            }
	        }
	    }
	    return true;
	    
}