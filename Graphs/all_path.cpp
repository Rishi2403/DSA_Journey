// #include<iostream>
// #include<vector>
// #include<unordered_map>
// #include<list>
// #include<unordered_set>
// using namespace std;

// vector<vector <int> >result ;
// class graph{

//     public:
//     unordered_map<int , list<int> >adj;
//     unordered_set<int> visited;
//     //vector<vector <int> >result ;
//     void addEdge(int u , int v , bool direction){
//         //direction =0  -> undirected 
//         // direction =1 -> dirceted 

//         //create an edge from u to v
//         adj[u].push_back(v);

//         if(direction == 0){
//             adj[v].push_back(u);
//         }    
//     }
//     void printAdjList(){
//         for (auto i:adj){
//             cout<< i.first <<"->";
//         for(auto j: i.second){
//             cout<< j<< " ,";        
//         }
//         cout<<"\n";
//         }
//     }

//     void dfs(int curr , int end ,vector<int> &path ){

//         if (curr==end) {
//             path.push_back(curr);
//             result.push_back(path);
//             path.pop_back();
//             return;
//         }
//         visited.insert(curr);// mark visited
//         for(auto neighbour: adj[curr]){
//             if(not visited.count(neighbour)){
//                 dfs(neighbour , end , path);               
//             }
//         }
//         path.pop_back();
//         visited.erase(curr);
//         return ;
//     }
//     void allPath(int src , int dest){
//         vector<int> v;
//         dfs(src , dest ,v);
//     }

// };

// int main(){

//     int n ;
//     cout<<"Enter the number of nodes"<<"\n";
//     cin>> n;

//     int m;
//     cout<<"Enter the no of edges "<<"\n";
//     cin>>m;

//     graph g;
//     for(int i=0;i<m;i++){
//         int u , v;
//         cin>>u>>v;
//         //create an undirected graph
//         g.addEdge(u,v,0);
//     }
//     //printing graph
//     // g.printAdjList();
//     int x,y;
//     cin>>x>>y;
//     g.allPath(x,y);
//     for(auto path: result ){
//         for (auto el:path){
//             cout<<el<<" ";
//         }cout<<"\n";
//     }
   
//    return 0;
// }

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <list>
// #include <unordered_set>
// using namespace std;

// class graph {
// public:
//     unordered_map<int, list<int>> adj;
//     unordered_set<int> visited;
//     vector<vector<int>> result;

//     void addEdge(int u, int v, bool direction) {
//         adj[u].push_back(v);

//         if (direction == 0) {
//             adj[v].push_back(u);
//         }
//     }

//     void printAdjList() {
//         for (auto i : adj) {
//             cout << i.first << "->";
//             for (auto j : i.second) {
//                 cout << j << " ,";
//             }
//             cout << "\n";
//         }
//     }

//     void dfs(int curr, int end, vector<int> &path) {
//         if (curr == end) {
//            // path.push_back(curr);
//             result.push_back(path);
//             visited.erase(curr);
//             path.pop_back();
//             return;
//         }

//         visited.insert(curr);
//         for (auto neighbour : adj[curr]) {
//             if (not visited.count(neighbour)) {
//                 //path.push_back(curr);
//                 dfs(neighbour, end, path);
//             }
//         }

//         path.pop_back();
//         visited.erase(curr);
//         return;
//     }

//     vector<vector<int>> allPath(int src, int dest) {
//         vector<int> v;
//         dfs(src, dest, v);
//         return result;
//     }
// };

// int main() {
//     int n;
//     cout << "Enter the number of nodes" << "\n";
//     cin >> n;

//     int m;
//     cout << "Enter the no of edges " << "\n";
//     cin >> m;

//     graph g;
//     for (int i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;
//         g.addEdge(u, v, 0);
//     }

//     int x, y;
//     cin >> x >> y;
//     vector<vector<int>> paths = g.allPath(x, y);

//     for (auto path : paths) {
//         for (auto el : path) {
//             cout << el << " ";
//         }
//         cout << "\n";
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <unordered_set>
using namespace std;

class graph {
public:
    unordered_map<int, list<int>> adj;
    unordered_set<int> visited;
    vector<vector<int>> result;

    void addEdge(int u, int v, bool direction) {
        adj[u].push_back(v);

        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << "->";
            for (auto j : i.second) {
                cout << j << " ,";
            }
            cout << "\n";
        }
    }

    void dfs(int curr, int end, vector<int> &path) {
        visited.insert(curr);
        path.push_back(curr);

        if (curr == end) {
            result.push_back(path);
            // Don't continue with this path, return to explore other paths.
            visited.erase(curr);
            path.pop_back();
            return;
        }

        for (auto neighbour : adj[curr]) {
            if (!visited.count(neighbour)) {
                dfs(neighbour, end, path);
            }
        }

        // Backtrack
        visited.erase(curr);
        path.pop_back();
        return;
    }

    vector<vector<int>> allPath(int src, int dest) {
        vector<int> v;
        dfs(src, dest, v);
        return result;
    }
};

int main() {
    int n;
    cout << "Enter the number of nodes" << "\n";
    cin >> n;

    int m;
    cout << "Enter the no of edges " << "\n";
    cin >> m;

    graph g;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    int x, y;
    cin >> x >> y;
    vector<vector<int>> paths = g.allPath(x, y);

    for (auto path : paths) {
        for (auto el : path) {
            cout << el << " ";
        }
        cout << "\n";
    }

    return 0;
}
