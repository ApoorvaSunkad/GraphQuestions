#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Graph{
public:
    unordered_map<int, vector<int>> adj;

    void addEdge(int u, int v, bool direction){
        //direction - 0 -> undirected graph
        //direction - 1 -> directed graph

        //add an edge from u to v
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto it:adj){
            cout << it.first << "->";
            for(auto j:it.second){
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main(){
    int n;
    cout << "Enter the no. of nodes: ";
    cin>>n;
    int m;
    cout << "Enter the no. of edges: ";
    cin>>m;

    Graph g;
    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v;
        //creating an undirected graph
        g.addEdge(u,v,0);
    }
    g.printAdjList();
}