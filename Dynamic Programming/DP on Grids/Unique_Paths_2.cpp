// Given two values M and N, which represent a matrix[M][N].
// We need to find the total unique paths from the top-left cell (matrix[0][0]) to the rightmost cell (matrix[M-1][N-1]).
// At any cell we are allowed to move in only two directions:- bottom and right.



#include <bits/stdc++.h>
using namespace std;



// Memoization
// TC - O(M * N)
// TC - O(M * N) + O((M - 1) + (N - 1))



int mazeObstaclesUtil(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &dp)
{
    if (i > 0 && j > 0 && maze[i][j] == -1) return 0;
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int up = mazeObstaclesUtil(i - 1, j, maze, dp);
    int left = mazeObstaclesUtil(i, j - 1, maze, dp);

    return dp[i][j] = up + left;
}



// Tabulation
// TC - O(M * N)
// TC - O(M * N) 



int mazeObstaclesUtil(int n, int m, vector<vector<int>> &maze,vector<vector<int>>
 &dp) 
{

    for(int i=0; i<n ;i++){
        for(int j=0; j<m; j++){
            
            //base conditions
            if(i>0 && j>0 && maze[i][j]==-1){
                dp[i][j]=0;
                continue;
            }

            if(i==0 && j==0){
                dp[i][j]=1;
                continue;
            }
            
            int up=0;
            int left = 0;
            
            if(i>0) up = dp[i-1][j];
            if(j>0) left = dp[i][j-1];
                
            dp[i][j] = up+left;
        }
    }
  
    return dp[n-1][m-1];  
}



// Space Optimization
// TC - O(M * N)
// SC - O(N)


int mazeObstacles(int n, int m, vector<vector<int> > &maze){

    vector<int> prev(m,0);

    for(int i=0; i<n; i++){
        vector<int> temp(m,0);

        for(int j=0; j<m; j++){

            if(i>0 && j>0 && maze[i][j]==-1){
                temp[j]=0;
                continue;
            }

            if(i==0 && j==0){
                temp[j]=1;
                continue;
            }
            
            int up=0;
            int left =0;
            
            if(i>0) up = prev[j];
            if(j>0) left = temp[j-1];
                
            temp[j] = up + left;
        }

        prev = temp;
    }
    
    return prev[n-1];    
}



int mazeObstacles(int n, int m, vector<vector<int>> &maze)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return mazeObstaclesUtil(n - 1, m - 1, maze, dp);

}

int main()
{

    vector<vector<int>> maze{{0, 0, 0},
                             {0, -1, 0},
                             {0, 0, 0}};

    int n = maze.size();
    int m = maze[0].size();

    cout << mazeObstacles(n, m, maze);
}