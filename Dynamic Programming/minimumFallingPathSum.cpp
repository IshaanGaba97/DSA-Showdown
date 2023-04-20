#include <iostream>
#include<vector>
#include<algorithm> 

using namespace std;

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& a, vector<vector<int>>& dp){
        if(j < 0 || j >= a.size()) return INT_MAX;

        if(i == 0) return a[0][j];

        if(dp[i][j] != -1) return dp[i][j];

        int up = f(i-1, j, a, dp);
        int dl = f(i-1, j-1, a, dp);
        int dr = f(i-1, j+1, a, dp);

        return dp[i][j] = a[i][j] + min(up, min(dl, dr));
    }
    int minFallingPathSum(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();

        vector<vector<int>> dp(m, vector<int> (n, -1));

        int mini = INT_MAX; 
        for(int i = 0; i < n; i++){
            int temp = f(m-1, i, a, dp);
            mini = min(temp, mini);
        }

        return mini;
    }
};