#include <iostream>
#include<vector>
#include<algorithm> 
using namespace std;

int f(int ind, int tar, vector<int> &a, vector<vector<int>> &dp){
    if(ind == 0){
    if(tar == 0 && a[0] == 0) return 2;
    if(tar == 0 || a[0] == tar) return 1;
    return 0;
    }
    if(dp[ind][tar] != -1) return dp[ind][tar];
    
    int notTake = f(ind-1, tar, a, dp);
    int take = 0;
    if(a[ind] <= tar){
        take = f(ind-1, tar-a[ind], a, dp);
    }

    return dp[ind][tar] = take + notTake;
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, -1));
    
    return f(n-1, tar, num, dp);
}