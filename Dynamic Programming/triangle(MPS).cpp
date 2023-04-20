#include <iostream>
#include<vector>
#include<algorithm> 

using namespace std;
class Solution {
public:
    //  ending point is not fixed but starting point is fixed
    int f(int i, int j, int m, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i == m-1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down = triangle[i][j] + f(i+1, j, m, triangle, dp);
        int diag = triangle[i][j] + f(i+1, j+1, m, triangle, dp);

        return dp[i][j] = min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();   //no. of rows;
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0, 0, m, triangle, dp);
    }
};