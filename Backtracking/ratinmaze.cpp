#include<iostream>
#include<vector>
using namespace std;

bool canWeGo(int a, int b, vector<vector<int> > &grid){

    return (a < grid.size() and b < grid.size() and a>=0 and b>=0) and grid[a][b]==1;
}

int f(int i, int j, vector<vector<int> > &grid){

    int n=grid.size();

    if(i==n-1 and j==n-1)
    {
        for(int i=0;i<n;i++)   // for visualisation of rats movement
        {
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }cout<<"\n";
        }cout<<"---------------\n";

        return 1;
    }
    
    int ans=0;
    grid[i][j]=2;  // marking that this grid is being visited

    if(canWeGo(i,j+1,grid)) //right
        ans+=f(i,j+1,grid);
    if(canWeGo(i+1,j,grid)) //down
        ans+=f(i+1,j,grid);
    if(canWeGo(i-1,j,grid)) //up
        ans+=f(i-1,j,grid);
    if(canWeGo(i,j-1,grid))//left
        ans+=f(i,j-1,grid);

    grid[i][j]=1; // reseting back the grid to usual mark so to explore more roads while backtracking
    return ans;
}

int main()
{

    vector<vector<int> > grid={ 
        {1,1,1,1},
        {0,1,0,1},
        {0,1,1,1},
        {0,1,1,1}
    };
    cout<<f(0,0,grid);

    return 0;
}