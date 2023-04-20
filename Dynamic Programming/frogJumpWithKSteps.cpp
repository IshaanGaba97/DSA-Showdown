#include <iostream>
#include<vector>
#include<algorithm> 
using namespace std;
int f(int ind, vector<int> &dp, vector<int> &heights, int k){
    if(ind == 0) return 0;

    if(dp[ind] != -1) return dp[ind];
    int minSteps = INT_MAX;
    for(int j = 1; j <=k; j++){
        if(ind - j > 0){
            int jumps = f(ind-j, dp, heights, k) + abs(heights[ind] - heights[ind-j]);
            minSteps = min(minSteps, jumps);
        }
    }
    return dp[ind] = minSteps;
}
int frogJump(int n, vector<int> &heights, int k)
{
    vector<int> dp(n+1, -1);
    return f(n-1, dp, heights, k);
}