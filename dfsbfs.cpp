#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;

map<int,list<int>> adjList;
map<int,bool> visited;
queue<int> q;

void addEdge(int u,int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u); // For undirected graph
}

void dfs(int node){
    visited[node] = true;
    cout<<node<<" ";
    for(auto i:adjList[node]){
        if(!visited[i]){
            dfs(i);
        }
    }
}

void bfs(int startNode){
    q.push(startNode);
    visited[startNode] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(auto i:adjList[node]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    int n,e;
    cout<<"Enter the number of nodes and edges:";
    cin>>n>>e;
    cout<<"Enter the "<<e<<"edges (u v): "<<endl;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
    }
    
    cout<<"DFS Traversal enter the starting node: ";
    int startNode;
    cin>>startNode;
    cout<<"DFS Traversal: ";
    dfs(startNode);                  
    cout<<endl;

    for(int i=0;i<n;i++){
        visited[i] = 0;
    }

    cout<<"BFS Traversal enter the starting node: ";
    cin>>startNode;
    bfs(startNode);
    cout<<endl;
    
    return 0;
}