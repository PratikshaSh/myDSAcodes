#include<iostream>
using namespace std;
//M X N matrix with some cells blocked
//1.Find path from src to dest
//2. Count the no. of paths from src to dest
//3. print all possible paths(HERE)
//rat moves only in forward and down

bool ratInMaze(char maze[10][10], int sol[][10], int i, int j, int m, int n){
    if(i==m and j==n){
        sol[m][n] = 1;
        //print the path
        for(int i=0; i<=m;i++){
            for(int j=0; j<=n;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    //Rat should be inside the grid 
    if(i>m or j>n){
        return false;
    }
    if(maze[i][j]=='X'){
        return false;

    }
    //assume sol exists thru current cell
    sol[i][j]=1;

    bool rightSuccess = ratInMaze(maze, sol, i, j+1, m, n);
    bool downSuccess  =ratInMaze(maze, sol, i+1, j, m, n);
    //backtracking
     sol[i][j]=0;
    if(rightSuccess || downSuccess){
        return true;
    }
    return false;
   
}

int main(){

    char maze[10][10] = {
                        "0000",
                        "00X0",
                        "000X",
                        "0X00",
    };
    int soln[10][10]={0};
    int m=4,n=4;

    bool ans = ratInMaze(maze, soln, 0,0,m-1, n-1);

    if(ans == false){
        cout<<"Path doesn't exist !!!";

    }

    return 0;
}