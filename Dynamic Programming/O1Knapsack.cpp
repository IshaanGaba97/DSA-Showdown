#include <iostream>
#include<vector>
#include<algorithm> 

using namespace std;

class Solution
{
    public:
        int f(int ind, int W, int wt[], int val[], vector<vector<int>> &dp){
        if(ind == 0){
            if(wt[0] <= W) return val[0];
            else return 0;
        }
        if(dp[ind][W] != -1) return dp[ind][W];

        int notTake = 0 + f(ind-1, W, wt, val, dp);
        int take = INT_MIN;
        if(wt[ind] <= W){
            take = val[ind] + f(ind-1, W- wt[ind], wt, val, dp);
        }
        
        return dp[ind][W] = max(notTake, take);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    {
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return f(n-1, W, wt, val, dp);
    }
};


class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    {
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        
        for(int i = wt[0]; i <= W; i++){
                dp[0][i] = val[0];
        }
        
            for(int i = 1; i < n; i++){
                for(int j = 0; j <= W; j++){
                    int notTake = dp[i-1][j];
                    int take = INT_MIN;
                    if(wt[i] <= j){
                        take = val[i] + dp[i-1][j-wt[i]];
                    }
                    
                    dp[i][j] = max(notTake, take);
                }
            }
            
            
        return dp[n-1][W];
    }
};