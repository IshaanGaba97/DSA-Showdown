#include <iostream>
#include<vector>
#include<algorithm> 
using namespace std;

class Solution {
public:
    int f(int i, int j1, int j2, vector<vector<int>>& grid, int r, int c, vector<vector<vector<int>>> &dp){
        if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c){
            return -1e8;
        }
        if(i == r-1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        // explore all paths of r1 and r2 simulataneously
        int maxi = -1e8;
        for(int dj1 = -1; dj1 <= 1; dj1++){
            for(int dj2 = -1; dj2 <= 1; dj2++){
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += + f(i+1, j1+dj1, j2+dj2, grid, r , c, dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        //int dp[r][c][c];
        vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c, -1)));
        return f(0, 0, c-1, grid, r, c, dp);
    }
};