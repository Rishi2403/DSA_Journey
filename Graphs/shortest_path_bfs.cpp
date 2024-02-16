#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class graph{

    public:
    unordered_map<int , list<int> >adj;

    void addEdge(int u , int v , bool direction){
        //direction =0  -> undirected 
        // direction =1 -> dirceted 

        //create an edge from u to v
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }    
    }
    void printAdjList(){
        for (auto i:adj){
            cout<< i.first <<"->";
        for(auto j: i.second){
            cout<< j<< " ,";        
        }
        cout<<"\n";
        }
    }
    void bfs(int src , int dest , vector<index> &dist){
        queue<int> qu;
        visited.clear();
        dist[src]=0;
        visited
    }

};

int main(){

    int n ;
    cout<<"Enter the number of nodes"<<"\n";
    cin>> n;

    int m;
    cout<<"Enter the no of edges "<<"\n";
    cin>>m;

    graph g;
    for(int i=0;i<m;i++){
        int u , v;
        cin>>u>>v;
        //create an undirected graph
        g.addEdge(u,v,0);
    }
    //printing graph
    g.printAdjList();
}