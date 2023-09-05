#include<iostream>
#include<vector>
using namespace std;

bool canplaceQueen(int currRow,int col, vector<vector<char> >&grid){

    //check verticals
    for(int i=currRow-1;i>=0;i--){
        if(grid[i][col]=='Q')
        return false;
    }

    //check up left diagonal
    for(int i=currRow-1,j=col-1;i>=0 and j>=0;i--,j--){
        if(grid[i][j]=='Q')
        return false;
    }

    //check up right diagonal
    for(int i=currRow-1,j=col+1;i>=0 and j<grid.size();i--,j++){
        if(grid[i][j]=='Q')
        return false;
    }
    return true;

}

void nqueen(int currRow,int n, vector<vector<char> >&grid){
    if(currRow==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }cout<<endl;
        }cout<<" -------- \n";
    }

    for(int col=0;col<n;col++){
        //shall go to all cols and see whether we can place the queen

        if(canplaceQueen(currRow,col,grid)){
            grid[currRow][col]='Q';
            nqueen(currRow+1 ,n, grid);
            grid[currRow][col]='.';
        }
    }
}
int main()
{
    int n=4;
    vector< vector<char> >grid(n,vector <char> (n , '.'));
    nqueen(0,n,grid);

    return 0;
}