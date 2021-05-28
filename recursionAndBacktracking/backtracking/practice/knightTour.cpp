// C++ program for Knight Tour problem
#include <bits/stdc++.h>
using namespace std;

#define N 8

int solveKTUtil(int x, int y, int movei, int sol[N][N],
				int xMove[], int yMove[]);

/* A utility function to check if i,j are
valid indexes for N*N chessboard */
int isSafe(int x, int y, int sol[N][N])
{
	return (x >= 0 && x < N && y >= 0 && y < N
			&& sol[x][y] == -1);//true
}

/* A utility function to print
solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++)
			cout << " " << setw(2) << sol[x][y] << " ";
		cout << endl;
	}
}


int solveKT()
{
	int sol[N][N];

	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			sol[x][y] = -1;
	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	// Since the Knight is initially at the first block
	sol[0][0] = 0;

	if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
		cout << "Solution does not exist";
		return 0;
	}
	else
		printSolution(sol);

	return 1;
}

/* A recursive utility function to solve Knight Tour
problem */
int solveKTUtil(int x, int y, int movei, int sol[N][N],
				int xMove[N], int yMove[N])
{
    if(movei == N*N){
        return 1;
    }

    for(int k=0; k<8; k++){
        int next_x = x + xMove[k];
        int next_y = y + yMove[k];

        if(isSafe(next_x, next_y, sol)){
            sol[next_x][next_y] = movei;
           if(solveKTUtil(next_x, next_y, movei+1, sol, xMove, yMove) == 1)
           return 1;
           else{
                sol[next_x][next_y] = -1;

           }
        }


    }
    return 0;
	
}

// Driver Code
int main()
{
	// Function Call
	solveKT();
	return 0;
}

// This code is contributed by ShubhamCoder
