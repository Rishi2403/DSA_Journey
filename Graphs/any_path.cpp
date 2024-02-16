#include<iostream>
#include<unordered_map>
#include<list>
#include<unordered_set>
using namespace std;


class graph{

    public:
    unordered_map<int , list<int> >adj;
    unordered_set<int> visited;
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

    bool dfs(int curr , int end){

        if (curr==end) return true;
        visited.insert(curr);// mark visited
        for(auto neighbour: adj[curr]){
            if(not visited.count(neighbour)){
                bool result=dfs(neighbour , end);
                if (result)  return true;
            }
        }
        return false;
    }
    bool anyPath(int src , int dest){
        return dfs(src , dest);
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
    // g.printAdjList();
    int x,y;
    cin>>x>>y;
    cout<<g.anyPath(x,y)<<"\n";
   
   return 0;
}