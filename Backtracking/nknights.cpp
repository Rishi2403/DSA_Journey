#include<iostream>
#include<vector>
using namespace std;

bool canWePlace(vector<vector<char> > &grid, int i , int j){
    if(i-1>=0 and j-2>=0 and grid[i-1][j-2]=='K') return false;
    if(i-2>=0 and j-1>=0 and grid[i-2][j-1]=='K') return false;
    if(i-1>=0 and j+2>=0 and grid[i-1][j+2]=='K') return false;
    if(i-2>=0 and j+1>=0 and grid[i-2][j+1]=='K') return false;
    return true;
}

void knights(int m , int n , vector<vector<char> >&grid, int k,int i,int j){

    if(k==0){
        //allknights placed
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j];
            }cout<<'\n';
        }cout<<"__________\n";
        return;
    }
    if(j==n){
        return knights(m,n,grid,k,i+1,0);
    }
    if(i==m){
        return;
    }
    int row,col=0;
    for(row=i;row<m;row++){
        for(col=(row == i ? j : 0);col<n;col++){
                if(canWePlace(grid,row,col)){
                    grid[row][col]='K';
                    knights(m,n,grid,k-1,row,col+1);
                    grid[row][col]=' ';
                 }
        }
    }

}

int main()
{
    int n=3,m=3;
    vector<vector<char> >grid (n,vector<char> (m, ' '));
    knights(m,n,grid,5,0,0);
    return 0;
}